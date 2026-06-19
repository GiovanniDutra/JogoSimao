#include "FaseSegunda.h"
#include "Pinguim.h"
#include "Plataforma.h"
#include "EspinhoGelo.h"
#include "GolemGelo.h"
#include <iostream>
#include "GerenciadorGrafico.h"

namespace TrabalhoJogo {
	namespace Fases {

		FaseSegunda::FaseSegunda() : Fase() {
			carregaFundo("assets/cenariofrio2.png"); // novo fundo
			criarCenario();
		}

		FaseSegunda::~FaseSegunda() {}

		void FaseSegunda::criarInimigos() {

			Entidades::Personagens::Pinguim* p1 =
				new Entidades::Personagens::Pinguim(400, 650, 350, 600);

			Entidades::Personagens::Pinguim* p2 =
				new Entidades::Personagens::Pinguim(900, 500, 850, 1100);

			listaEnts.incluirEntidade(p1);
			listaEnts.incluirEntidade(p2);

			pGC->incluirInimigo(p1);
			pGC->incluirInimigo(p2);
		}

		void FaseSegunda::carregaFundo(const std::string& caminho)
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

		void FaseSegunda::criarObstaculos() {
			using namespace Entidades::Obstaculos;

			EspinhoGelo* e1 = new EspinhoGelo();
			EspinhoGelo* e2 = new EspinhoGelo();

			e1->setPosicao(400, 820);
			e2->setPosicao(750, 820);

			listaEnts.incluirEntidade(e1);
			listaEnts.incluirEntidade(e2);

			pGC->incluirObstaculo(e1);
			pGC->incluirObstaculo(e2);
		}
		void FaseSegunda::criarEspinhoGelo() {
			Entidades::Obstaculos::EspinhoGelo* pEspinhoGelo1 =
				new Entidades::Obstaculos::EspinhoGelo(725, 750, 350.0f, 50.0f);

			Entidades::Obstaculos::EspinhoGelo* pEspinhoGelo2 =
				new Entidades::Obstaculos::EspinhoGelo(200, 315, 350.0f, 50.0f);

			Entidades::Obstaculos::EspinhoGelo* pEspinhoGelo3 =
				new Entidades::Obstaculos::EspinhoGelo(1250, 280, 350.0f, 50.0f);

			listaEnts.incluirEntidade(pEspinhoGelo1);
			listaEnts.incluirEntidade(pEspinhoGelo2);
			listaEnts.incluirEntidade(pEspinhoGelo3);

			if (pGC != NULL) {
				pGC->incluirObstaculo(pEspinhoGelo1);
				pGC->incluirObstaculo(pEspinhoGelo2);
				pGC->incluirObstaculo(pEspinhoGelo3);
			}
		}
		void FaseSegunda::criarGolemGelo() {
			Entidades::Personagens::GolemGelo* pGolemGelo1 =
				new Entidades::Personagens::GolemGelo(650, 605, 630, 670);

			Entidades::Personagens::GolemGelo* pGolemGelo2 =
				new Entidades::Personagens::GolemGelo(560, 415, 540, 580);

			Entidades::Personagens::GolemGelo* pGolemGelo3 =
				new Entidades::Personagens::GolemGelo(940, 315, 920, 960);

			listaEnts.incluirEntidade(pGolemGelo1);
			listaEnts.incluirEntidade(pGolemGelo2);
			listaEnts.incluirEntidade(pGolemGelo3);

			if (pGC != NULL) {
				pGC->incluirInimigo(pGolemGelo1);
				pGC->incluirInimigo(pGolemGelo2);
				pGC->incluirInimigo(pGolemGelo3);
			}
		}
	}
}