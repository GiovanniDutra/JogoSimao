#include "Fase.h"
#include "GerenciadorColisoes.h"
#include "Plataforma.h"
#include "Jogador.h"
#include "Pinguim.h"
#include "GerenciadorGrafico.h"
#include <iostream>

namespace TrabalhoJogo {
	namespace Fases {
		Fase::Fase() : Ente(), 
			pGC(new Gerenciadores::GerenciadorColisoes()),
			pJog1(NULL), limiteChao(900)
		{

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

		void Fase::criarPinguins() { //Criar Inimigos Faceis
			Entidades::Personagens::Pinguim* pPinguim1 =
				new Entidades::Personagens::Pinguim(260, 660, 150, 440);

			Entidades::Personagens::Pinguim* pPinguim2 =
				new Entidades::Personagens::Pinguim(580, 430, 520, 760);

			Entidades::Personagens::Pinguim* pPinguim3 =
				new Entidades::Personagens::Pinguim(950, 330, 880, 1130);

			listaEnts.incluirEntidade(pPinguim1);
			listaEnts.incluirEntidade(pPinguim2);
			listaEnts.incluirEntidade(pPinguim3);

			if(pGC != NULL) {
				pGC->incluirInimigo(pPinguim1);
				pGC->incluirInimigo(pPinguim2);
				pGC->incluirInimigo(pPinguim3);
			}
		}


		void Fase::criarPlataformas() {	
			Entidades::Obstaculos::Plataforma* pPlat1 =
				new Entidades::Obstaculos::Plataforma(150, 735, 350, 50);

			Entidades::Obstaculos::Plataforma* pPlat2 =
				new Entidades::Obstaculos::Plataforma(500, 565, 350, 50);

			Entidades::Obstaculos::Plataforma* pPlat3 =
				new Entidades::Obstaculos::Plataforma(860, 415, 350, 50);

			Entidades::Obstaculos::Plataforma* pPlat4 =
				new Entidades::Obstaculos::Plataforma(1200, 665, 350, 50);

			Entidades::Obstaculos::Plataforma* pPlat5 =
				new Entidades::Obstaculos::Plataforma(1500, 465, 350, 50);

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

			criarPinguins(); //Criar Inim Faceis
			criarObstaculos();
			criarPlataformas();
			criarInimigos();
		}
	}
}
