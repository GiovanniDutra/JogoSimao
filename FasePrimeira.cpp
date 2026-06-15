#include "FasePrimeira.h"
#include "LoboGelo.h"
#include "PlataformaGelida.h"

namespace TrabalhoJogo {
	namespace Fases {
		FasePrimeira::FasePrimeira() :
			Fase(),
			maxLoboGelo(10)
		{
			criarCenario();
		}

		FasePrimeira::~FasePrimeira() {}

		void FasePrimeira::criarInimigos() {
			criarLoboGelo();
		}

		void FasePrimeira::criarObstaculos() {
			criarObstMedios();
		}

		void FasePrimeira::criarLoboGelo() {
			Entidades::Personagens::LoboGelo* pLoboGelo1 =
				new Entidades::Personagens::LoboGelo(650, 605, 580, 820);

			Entidades::Personagens::LoboGelo* pLoboGelo2 =
				new Entidades::Personagens::LoboGelo(560, 415, 520, 730);

			Entidades::Personagens::LoboGelo* pLoboGelo3 =
				new Entidades::Personagens::LoboGelo(940, 315, 880, 1100);

			listaEnts.incluirEntidade(pLoboGelo1);
			listaEnts.incluirEntidade(pLoboGelo2);
			listaEnts.incluirEntidade(pLoboGelo3);

			if(pGC != NULL) {
				pGC->incluirInimigo(pLoboGelo1);
				pGC->incluirInimigo(pLoboGelo2);
				pGC->incluirInimigo(pLoboGelo3);
			}
		}

		void FasePrimeira::criarObstMedios() {
			Entidades::Obstaculos::PlataformaGelida* pPlataformaGelida1 =
				new Entidades::Obstaculos::PlataformaGelida(725, 750, 350.0f, 50.0f);

			Entidades::Obstaculos::PlataformaGelida* pPlataformaGelida2 =
				new Entidades::Obstaculos::PlataformaGelida(200, 315, 350.0f, 50.0f);

			Entidades::Obstaculos::PlataformaGelida* pPlataformaGelida3 =
				new Entidades::Obstaculos::PlataformaGelida(1250, 280, 350.0f, 50.0f);

			listaEnts.incluirEntidade(pPlataformaGelida1);
			listaEnts.incluirEntidade(pPlataformaGelida2);
			listaEnts.incluirEntidade(pPlataformaGelida3);

			if(pGC != NULL) {
				pGC->incluirObstaculo(pPlataformaGelida1);
				pGC->incluirObstaculo(pPlataformaGelida2);
				pGC->incluirObstaculo(pPlataformaGelida3);
			}
		}


	}
}
