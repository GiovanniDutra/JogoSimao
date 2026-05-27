#include "FasePrimeira.h"
#include "InimMedio.h"
#include "ObstMedio.h"

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
			Entidades::Obstaculos::ObstMedio* pObstMedio1 = new Entidades::Obstaculos::ObstMedio(300, 600);

			listaEnts.incluirEntidade(pObstMedio1);

			if(pGC != NULL) {
				pGC->incluirObstaculo(pObstMedio1);
			}
		}
	}
}
