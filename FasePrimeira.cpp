#include "FasePrimeira.h"
#include "InimMedio.h"
#include "ObstMedio.h"

namespace TrabalhoJogo {
	namespace Fases {
		FasePrimeira::FasePrimeira() :
			Fase(),
			maxInimMedios(10)
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
			Entidades::Personagens::InimMedio* pInimMedio1 =
				new Entidades::Personagens::InimMedio(650, 605, 580, 820);

			Entidades::Personagens::InimMedio* pInimMedio2 =
				new Entidades::Personagens::InimMedio(560, 415, 520, 730);

			Entidades::Personagens::InimMedio* pInimMedio3 =
				new Entidades::Personagens::InimMedio(940, 315, 880, 1100);

			listaEnts.incluirEntidade(pInimMedio1);
			listaEnts.incluirEntidade(pInimMedio2);
			listaEnts.incluirEntidade(pInimMedio3);

			if(pGC != NULL) {
				pGC->incluirInimigo(pInimMedio1);
				pGC->incluirInimigo(pInimMedio2);
				pGC->incluirInimigo(pInimMedio3);
			}
		}

		void FasePrimeira::criarObstMedios() {
			Entidades::Obstaculos::ObstMedio* pObstMedio1 =
				new Entidades::Obstaculos::ObstMedio(430, 590);

			Entidades::Obstaculos::ObstMedio* pObstMedio2 =
				new Entidades::Obstaculos::ObstMedio(620, 400);

			Entidades::Obstaculos::ObstMedio* pObstMedio3 =
				new Entidades::Obstaculos::ObstMedio(980, 300);

			listaEnts.incluirEntidade(pObstMedio1);
			listaEnts.incluirEntidade(pObstMedio2);
			listaEnts.incluirEntidade(pObstMedio3);

			if(pGC != NULL) {
				pGC->incluirObstaculo(pObstMedio1);
				pGC->incluirObstaculo(pObstMedio2);
				pGC->incluirObstaculo(pObstMedio3);
			}
		}


	}
}
