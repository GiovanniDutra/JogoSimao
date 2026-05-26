#include "FasePrimeira.h"
#include "InimMedio.h"

namespace TrabalhoJogo {
	namespace Fases {
		FasePrimeira::FasePrimeira() :
			Fase(),
			maxInimMedios(3)
		{
			criarCenario();
		}

		FasePrimeira::~FasePrimeira() {}

		void FasePrimeira::criarInimigos() {
			criarInimMedios();
		}

		void FasePrimeira::criarObstaculos() {
			criarObstMedios();
		}

		void FasePrimeira::criarInimMedios() {
			Entidades::Personagens::InimMedio* pInimMedio = new Entidades::Personagens::InimMedio();

			listaEnts.incluirEntidade(pInimMedio);

			if(pGC != NULL) {
				pGC->incluirInimigo(pInimMedio);
			}
		}

		void FasePrimeira::criarObstMedios() {
			//Implementar Quando Obstaculo Medio Existir
		}
	}
}
