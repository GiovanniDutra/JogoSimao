#include "Fase.h"
#include "GerenciadorColisoes.h"
#include "Plataforma.h"
#include "Jogador.h"
#include "InimFacil.h"
#include "GerenciadorGrafico.h"
#include <iostream>

namespace TrabalhoJogo {
	namespace Fases {
		Fase::Fase() : Ente(), 
			pGC(new Gerenciadores::GerenciadorColisoes()),
			pJog1(NULL), limiteChao(900)
		{
			carregaFundo("assets/cenariofrio.jfif");

			if (pGC != NULL) {
				pGC->setLimiteChao(limiteChao);
			}
		}

		Fase::~Fase() {
			delete pGC;
			pGC = NULL;
			pJog1 = NULL;
		}

		void Fase::executar() {
			pGG->getJanela().draw(fundo);

			listaEnts.percorrer();

			if(pGC != NULL) {
				pGC->executar();
			}

			listaEnts.desenhar();

			if (pJog1 && pJog1->getNumVidas() <= 0)
			{
				pGG->fecharJanela();
			}
		}

		void Fase::criarInimFaceis() {
			Entidades::Personagens::InimFacil* pInimFacil1 =
				new Entidades::Personagens::InimFacil(260, 660, 150, 340);

			Entidades::Personagens::InimFacil* pInimFacil2 =
				new Entidades::Personagens::InimFacil(580, 430, 520, 730);

			Entidades::Personagens::InimFacil* pInimFacil3 =
				new Entidades::Personagens::InimFacil(950, 330, 880, 1100);

			listaEnts.incluirEntidade(pInimFacil1);
			listaEnts.incluirEntidade(pInimFacil2);
			listaEnts.incluirEntidade(pInimFacil3);

			if(pGC != NULL) {
				pGC->incluirInimigo(pInimFacil1);
				pGC->incluirInimigo(pInimFacil2);
				pGC->incluirInimigo(pInimFacil3);
			}
		}

		void Fase::carregaFundo(const std::string& caminho) 
		{
			if (!texturaFundo.loadFromFile(caminho)) {
				std::cout << "Erro ao carregar fundo: " << caminho << std::endl;
				return;
			}

			fundo.setTexture(texturaFundo);

			sf::Vector2u tamTextura = texturaFundo.getSize();
			sf::Vector2u tamJanela = pGG->getJanela().getSize();

			fundo.setScale(
				static_cast<float>(tamJanela.x) / tamTextura.x,
				static_cast<float>(tamJanela.y) / tamTextura.y
			);
		}

		void Fase::criarPlataformas() {	
			Entidades::Obstaculos::Plataforma* pPlat1 =
				new Entidades::Obstaculos::Plataforma(150, 720, 200, 20);

			Entidades::Obstaculos::Plataforma* pPlat2 =
				new Entidades::Obstaculos::Plataforma(500, 550, 200, 20);

			Entidades::Obstaculos::Plataforma* pPlat3 =
				new Entidades::Obstaculos::Plataforma(860, 385, 200, 20);

			Entidades::Obstaculos::Plataforma* pPlat4 =
				new Entidades::Obstaculos::Plataforma(1200, 650, 200, 20);

			Entidades::Obstaculos::Plataforma* pPlat5 =
				new Entidades::Obstaculos::Plataforma(1500, 450, 200, 20);

			listaEnts.incluirEntidade(pPlat1);
			listaEnts.incluirEntidade(pPlat2);
			listaEnts.incluirEntidade(pPlat3);
			listaEnts.incluirEntidade(pPlat4);
			listaEnts.incluirEntidade(pPlat5);

			if (pGC != NULL)
			{
				pGC->incluirObstaculo(pPlat1);
				pGC->incluirObstaculo(pPlat2);
				pGC->incluirObstaculo(pPlat3);
				pGC->incluirObstaculo(pPlat4);
				pGC->incluirObstaculo(pPlat5);
			}
		}

		void Fase::criarCenario() {
			pJog1 = new Entidades::Personagens::Jogador();

			listaEnts.incluirEntidade(pJog1);

			if (pGC != NULL)
			{
				pGC->setJogador(pJog1);
			}

			criarInimFaceis();
			criarObstaculos();
			criarPlataformas();
			criarInimigos();
		}
	}
}
