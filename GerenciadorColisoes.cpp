#include "GerenciadorColisoes.h"

#include "Entidade.h"
#include "Jogador.h"
#include "Obstaculo.h"
#include "Projetil.h"
#include "Inimigo.h"
#include "EspinhoGelo.h"

#include <iostream>

namespace TrabalhoJogo {
	namespace Gerenciadores {
		GerenciadorColisoes::GerenciadorColisoes() : pJog1(NULL), limiteChao(0) {}

		GerenciadorColisoes::~GerenciadorColisoes() {
			LIs.clear();
			LOs.clear();
			LPs.clear();
			pJog1 = NULL;
		}

		void GerenciadorColisoes::setJogador(Entidades::Personagens::Jogador* pJogador) {
			pJog1 = pJogador;
		}

		bool const GerenciadorColisoes::verificarColisao(Entidades::Entidade* pE1, Entidades::Entidade* pE2) const {
			if (pE1 == NULL || pE2 == NULL) {
				return false;
			}

			if (!pE1->estaAtivo() || !pE2->estaAtivo()) {
				return false;
			}

			return pE1->getBody().getGlobalBounds().intersects(pE2->getBody().getGlobalBounds());
		}

		void GerenciadorColisoes::incluirInimigo(Entidades::Personagens::Inimigo* pI) {
			if (pI != NULL) {
				LIs.push_back(pI);
			}
		}

		void GerenciadorColisoes::incluirObstaculo(Entidades::Obstaculos::Obstaculo* pO) {
			if (pO != NULL) {
				LOs.push_back(pO);
			}
		}

		void GerenciadorColisoes::incluirProjetil(Entidades::Projetil* pP) {
			if (pP != NULL) {
				LPs.insert(pP);
			}
		}

		void GerenciadorColisoes::tratarColisoesJogsObstaculos() {
			if (pJog1 == NULL) {
				return;
			}

			std::list<Entidades::Obstaculos::Obstaculo*>::iterator it;

			for (it = LOs.begin(); it != LOs.end(); it++)
			{
				Entidades::Obstaculos::Obstaculo* pObstaculo = *it;

				if (pObstaculo != NULL)
				{
					if (verificarColisao(pJog1, pObstaculo))
					{
						tratarColisaoEntidadeObstaculo(pJog1, pObstaculo);

						pObstaculo->obstaculizar(pJog1);
					}
				}
			}
		}

		void GerenciadorColisoes::tratarColisoesInimigosObstaculos() {
			for (unsigned int i = 0; i < LIs.size(); i++)
			{
				Entidades::Personagens::Inimigo* pInimigo = LIs[i];

				if (pInimigo != NULL && pInimigo->estaAtivo())
				{
					std::list<Entidades::Obstaculos::Obstaculo*>::iterator it;

					for (it = LOs.begin(); it != LOs.end(); it++)
					{
						Entidades::Obstaculos::Obstaculo* pObstaculo = *it;

						if (pObstaculo != NULL && pObstaculo->estaAtivo())
						{
							if (verificarColisao(pInimigo, pObstaculo))
							{
								tratarColisaoEntidadeObstaculo(pInimigo, pObstaculo);
							}
						}
					}
				}
			}
		}

		void GerenciadorColisoes::tratarColisoesJogsInimigos() {
			if (pJog1 == NULL || !pJog1->estaAtivo())
			{
				return;
			}

			for (unsigned int i = 0; i < LIs.size(); i++)
			{
				Entidades::Personagens::Inimigo* pInimigo = LIs[i];

				if (pInimigo != NULL && pInimigo->estaAtivo())
				{
					if (pJog1->podeCausarDano())
					{
						sf::FloatRect areaAtaque = pJog1->getAreaAtaque();

						if (areaAtaque.intersects(pInimigo->getBody().getGlobalBounds()))
						{
							pInimigo->receberAtaque(pJog1->getForcaAtaque());
							pJog1->marcarDanoAplicado();

							if (!pInimigo->estaAtivo())
							{
								pJog1->addPontos(10);
								continue;
							}
						}
					}

					if (verificarColisao(pJog1, pInimigo))
					{
						sf::FloatRect jogador = pJog1->getBody().getGlobalBounds();
						sf::FloatRect inimigo = pInimigo->getBody().getGlobalBounds();

						float centroJogadorX = jogador.left + jogador.width / 2.0f;
						float centroInimigoX = inimigo.left + inimigo.width / 2.0f;

						float centroJogadorY = jogador.top + jogador.height / 2.0f;
						float centroInimigoY = inimigo.top + inimigo.height / 2.0f;

						float distanciaX = centroJogadorX - centroInimigoX;
						float distanciaY = centroJogadorY - centroInimigoY;

						float intersecaoX;
						float intersecaoY;

						if (distanciaX > 0)
						{
							intersecaoX = (inimigo.left + inimigo.width) - jogador.left;
						}
						else
						{
							intersecaoX = (jogador.left + jogador.width) - inimigo.left;
						}

						if (distanciaY > 0)
						{
							intersecaoY = (inimigo.top + inimigo.height) - jogador.top;
						}
						else
						{
							intersecaoY = (jogador.top + jogador.height) - inimigo.top;
						}

						if (intersecaoX < intersecaoY)
						{
							if (distanciaX > 0)
							{
								pJog1->setPosicao(pJog1->getX() + static_cast<int>(intersecaoX), pJog1->getY());
							}
							else
							{
								pJog1->setPosicao(pJog1->getX() - static_cast<int>(intersecaoX), pJog1->getY());
							}
						}
						else
						{
							if (distanciaY < 0)
							{
								pJog1->setPosicao(pJog1->getX(), pJog1->getY() - static_cast<int>(intersecaoY));
								pJog1->zerarVelocidadeY();
								pJog1->setNoChao(true);
							}
							else
							{
								pJog1->setPosicao(pJog1->getX(), pJog1->getY() + static_cast<int>(intersecaoY));
								pJog1->zerarVelocidadeY();
							}
						}

						pInimigo->danificar(pJog1);
					}
				}
			}
		}

		void GerenciadorColisoes::tratarColisoesJogsProjeteis() {
			if (pJog1 == NULL || !pJog1->estaAtivo())
			{
				return;
			}

			std::set<Entidades::Projetil*>::iterator it;

			for (it = LPs.begin(); it != LPs.end(); it++)
			{
				Entidades::Projetil* pProjetil = *it;

				if (pProjetil != NULL && pProjetil->estaAtivo())
				{
					if (verificarColisao(pJog1, pProjetil))
					{
						pJog1->receberDano(pProjetil->getDano());
						pProjetil->desativar();
					}
				}
			}
		}

		void GerenciadorColisoes::executar() {
			tratarColisoesEspinhoCenario();
			
			tratarColisoesJogsObstaculos();
			tratarColisoesInimigosObstaculos();

			if (pJog1 != NULL && pJog1->estaAtivo())
			{
				tratarColisaoChao(pJog1);
			}

			for(unsigned int i = 0; i < LIs.size(); i++) {
				if(LIs[i] != NULL && LIs[i]->estaAtivo()) {
					tratarColisaoChao(LIs[i]);
				}
			}

			tratarColisoesJogsInimigos();
			tratarColisoesJogsProjeteis();
		}

		void GerenciadorColisoes::setLimiteChao(int limite)
		{
			limiteChao = limite;
		}

		void GerenciadorColisoes::tratarColisaoChao(Entidades::Entidade* pEntidade)
		{
			if (pEntidade == NULL)
			{
				return;
			}

			sf::FloatRect corpo = pEntidade->getBody().getGlobalBounds();

			float base = corpo.top + corpo.height;

			if (base >= limiteChao)
			{
				int novoY = limiteChao - static_cast<int>(corpo.height);

				pEntidade->setPosicao(pEntidade->getX(), novoY);
				pEntidade->zerarVelocidadeY();
				pEntidade->setNoChao(true);
			}
		}

		void GerenciadorColisoes::tratarColisaoEntidadeObstaculo(Entidades::Entidade* pEntidade, Entidades::Obstaculos::Obstaculo* pObstaculo) {
			if (pEntidade == NULL || pObstaculo == NULL) {
				return;
			}

			const float toleranciaColisao = 25.0f;

			sf::FloatRect entidade = pEntidade->getBody().getGlobalBounds();
			sf::FloatRect obstaculo = pObstaculo->getBody().getGlobalBounds();

			float baseEntidade = entidade.top + entidade.height;
			float topoEntidade = entidade.top;

			float baseObstaculo = obstaculo.top + obstaculo.height;
			float topoObstaculo = obstaculo.top;

			bool dentroHorizontal = entidade.left + entidade.width > obstaculo.left &&
				                    entidade.left < obstaculo.left + obstaculo.width;

			bool bateuCima = pEntidade->getVelocidadeY() >= 0.0f &&
							 baseEntidade >= topoObstaculo &&
							 baseEntidade <= topoObstaculo + toleranciaColisao &&
							 dentroHorizontal;

			bool bateuBaixo = pEntidade->getVelocidadeY() < 0.0f &&
							  topoEntidade <= baseObstaculo &&
							  topoEntidade >= baseObstaculo - toleranciaColisao &&
							  dentroHorizontal;

			if (bateuCima) {
				int novoY = static_cast<int>(topoObstaculo - entidade.height);

				pEntidade->setPosicao(pEntidade->getX(), novoY);
				pEntidade->zerarVelocidadeY();
				pEntidade->setNoChao(true);
			}
			else if (bateuBaixo) {
				int novoY = static_cast<int>(baseObstaculo);

				pEntidade->setPosicao(pEntidade->getX(), novoY);
				pEntidade->zerarVelocidadeY();
			}
			else
			{
				float centroEntidade = entidade.left + entidade.width / 2.0f;
				float centroObstaculo = obstaculo.left + obstaculo.width / 2.0f;

				if (centroEntidade < centroObstaculo)
				{
					int novoX = static_cast<int>(obstaculo.left - entidade.width);
					pEntidade->setPosicao(novoX, pEntidade->getY());
				}
				else
				{
					int novoX = static_cast<int>(obstaculo.left + obstaculo.width);
					pEntidade->setPosicao(novoX, pEntidade->getY());
				}
			}
		}

		void GerenciadorColisoes::tratarColisoesEspinhoCenario() {
			std::list<Entidades::Obstaculos::Obstaculo*>::iterator it;

			for (it = LOs.begin(); it != LOs.end(); it++)
			{
				Entidades::Obstaculos::EspinhoGelo* pEspinho =
					dynamic_cast<Entidades::Obstaculos::EspinhoGelo*>(*it);

				if (pEspinho != NULL && !pEspinho->estaFixado())
				{
					sf::FloatRect corpo = pEspinho->getBody().getGlobalBounds();

					if (corpo.top + corpo.height >= limiteChao)
					{
						tratarColisaoChao(pEspinho);
						pEspinho->fixarCenario();
						continue;
					}

					std::list<Entidades::Obstaculos::Obstaculo*>::iterator it2;

					for (it2 = LOs.begin(); it2 != LOs.end(); it2++)
					{
						Entidades::Obstaculos::Obstaculo* pObstaculo = *it2;

						if (pObstaculo != NULL && pObstaculo != pEspinho)
						{
							Entidades::Obstaculos::EspinhoGelo* pOutroEspinho =
								dynamic_cast<Entidades::Obstaculos::EspinhoGelo*>(pObstaculo);

							if (pOutroEspinho == NULL && verificarColisao(pEspinho, pObstaculo))
							{
								tratarColisaoEntidadeObstaculo(pEspinho, pObstaculo);
								pEspinho->fixarCenario();
								break;
							}
						}
					}
				}
			}
		}
	}
}
