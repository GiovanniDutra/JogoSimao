#include "FasePrimeira.h"

namespace TrabalhoJogo {
	namespace Fases {
		FasePrimeira::FasePrimeira() :
			Fase(),
			maxInimMedios(5)
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
			//Implementar Quando Inimigo Medio Existir
		}

		void FasePrimeira::criarObstMedios() {
			//Implementar Quando Obstaculo Medio Existir
		}
	}
}
