#include "GerenciadorColisoes.h"

#include "Entidade.h"
#include "Jogador.h"
#include "Obstaculo.h"
#include "Projetil.h"
#include "Inimigo.h"

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
			for (unsigned int i = 0; i < LIs.size(); i++) {
				if (LIs[i] != NULL) {
					std::list<Entidades::Obstaculos::Obstaculo*>::iterator it;
					for (it = LOs.begin(); it != LOs.end(); it++)
					{
						Entidades::Obstaculos::Obstaculo* pObstaculo = *it;
						if (pObstaculo != NULL)
						{
							if (verificarColisao(LIs[i], pObstaculo))
							{
								tratarColisaoEntidadeObstaculo(LIs[i], pObstaculo);
							}
						}
					}
				}
			}
		}

		void GerenciadorColisoes::tratarColisoesJogsInimigos() {
			if(pJog1 == NULL) {
				return;
			}

			for (unsigned int i = 0; i < LIs.size(); i++) {
				if(LIs[i] != NULL) {
					if (verificarColisao(pJog1, LIs[i])) {
						LIs[i]->danificar(pJog1);
					}
				}
			}
		}

		void GerenciadorColisoes::tratarColisoesJogsProjeteis() {
			//Implementar Quando Projetil Existir
		}

		void GerenciadorColisoes::executar() {
			tratarColisoesJogsObstaculos();
			tratarColisoesInimigosObstaculos();

			tratarColisaoChao(pJog1);

			for(unsigned int i = 0; i < LIs.size(); i++) {
				if(LIs[i] != NULL) {
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
		}
	}
}
