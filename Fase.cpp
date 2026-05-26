#include "Fase.h"
#include "GerenciadorColisoes.h"

namespace TrabalhoJogo {
	namespace Fases {
		Fase::Fase() : Ente(), pGC(NULL) {
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
			//Implementar Quando Plataforma Existir
		}

		void Fase::criarCenario() {
			criarInimFaceis();
			criarObstaculos();
			criarPlataformas();
			criarInimigos();
		}
	}
}
