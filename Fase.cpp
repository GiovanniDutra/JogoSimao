#include "Fase.h"
#include "GerenciadorColisoes.h"
#include "Plataforma.h"
#include "Jogador.h"

namespace TrabalhoJogo {
	namespace Fases {
		Fase::Fase() : Ente(), pGC(NULL), pJog1(NULL) {
			pGC = new Gerenciadores::GerenciadorColisoes();
		}
		Fase::~Fase() {
			delete pGC;
			pGC = NULL;
		}

		void Fase::executar() {
			listaEnts.percorrer();

			if(pGC != NULL) {
				pGC->executar();
			}

			listaEnts.desenhar();
		}

		void Fase::criarInimFaceis() {
			//Implementar Quando Inimigo Existir
		}

		void Fase::criarPlataformas() {
			Entidades::Obstaculos::Plataforma* pPlat =
				new Entidades::Obstaculos::Plataforma();

			listaEnts.incluirEntidade(pPlat);

			if (pGC != NULL)
			{
				pGC->incluirObstaculo(pPlat);
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
