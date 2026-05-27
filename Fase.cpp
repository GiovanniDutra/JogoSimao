#include "Fase.h"
#include "GerenciadorColisoes.h"
#include "Plataforma.h"
#include "Jogador.h"
#include "InimFacil.h"

namespace TrabalhoJogo {
	namespace Fases {
		Fase::Fase() : Ente(), pGC(NULL), pJog1(NULL) {
			pGC = new Gerenciadores::GerenciadorColisoes();
		}
		Fase::~Fase() {
			delete pGC;
			pGC = NULL;
			pJog1 = NULL;
		}

		void Fase::executar() {
			listaEnts.percorrer();

			if(pGC != NULL) {
				pGC->executar();
			}

			listaEnts.desenhar();
		}

		void Fase::criarInimFaceis() {
			Entidades::Personagens::InimFacil* pInimFacil1 = new Entidades::Personagens::InimFacil();

			listaEnts.incluirEntidade(pInimFacil1);

			if(pGC != NULL) {
				pGC->incluirInimigo(pInimFacil1);
			}
		}

		void Fase::criarPlataformas() {
			Entidades::Obstaculos::Plataforma* pPlat1 =
				new Entidades::Obstaculos::Plataforma(0, 650, 900, 40);

			Entidades::Obstaculos::Plataforma* pPlat2 =
				new Entidades::Obstaculos::Plataforma(250, 520, 250, 30);

			Entidades::Obstaculos::Plataforma* pPlat3 =
				new Entidades::Obstaculos::Plataforma(600, 430, 250, 30);

			listaEnts.incluirEntidade(pPlat1);
			listaEnts.incluirEntidade(pPlat2);
			listaEnts.incluirEntidade(pPlat3);

			if (pGC != NULL)
			{
				pGC->incluirObstaculo(pPlat1);
				pGC->incluirObstaculo(pPlat2);
				pGC->incluirObstaculo(pPlat3);
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
