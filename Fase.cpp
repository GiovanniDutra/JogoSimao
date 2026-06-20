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
			pJog1(NULL), limiteChao(900),
			maxPinguins(10), maxPlataformas(10)
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
			int quantidade = gerarQuantidadeAleatoria(maxPinguins);

			int posicoes[10][4] = {  //X, Y, LimEsq, LimDir
			{260,  660, 150, 440},
			{580,  430, 520, 760},
			{950,  330, 880, 1130},
			{1260, 580, 1180, 1440},
			{1540, 380, 1480, 1720},
			{350,  820, 250, 520},
			{700,  700, 620, 880},
			{1080, 520, 1000, 1240},
			{1380, 760, 1300, 1560},
			{1650, 650, 1550, 1820}};

			for (int i = 0; i < quantidade; i++) {
				Entidades::Personagens::Pinguim* pPinguim =
					new Entidades::Personagens::Pinguim(
						posicoes[i][0],
						posicoes[i][1],
						posicoes[i][2],
						posicoes[i][3]
					);

				listaEnts.incluir(pPinguim);

				if (pGC != NULL) {
					pGC->incluirInimigo(pPinguim);
				}
			}
		}


		void Fase::criarPlataformas() {	
			int quantidade = gerarQuantidadeAleatoria(maxPlataformas);

			int posicoes[10][4] = { //X, Y, Largura, Altura
			{80,   820, 300, 45},
			{440,  700, 300, 45},
			{820,  560, 300, 45},
			{1200, 720, 300, 45},
			{1540, 580, 300, 45},
			{250,  430, 280, 45},
			{650,  300, 280, 45},
			{1050, 390, 280, 45},
			{1420, 260, 280, 45},
			{1580, 850, 260, 45}};

			for (int i = 0; i < quantidade; i++) {
				Entidades::Obstaculos::Plataforma* pPlat =
					new Entidades::Obstaculos::Plataforma(
						posicoes[i][0], //X
						posicoes[i][1], //Y
						posicoes[i][2], //Largura
						posicoes[i][3]  //Altura
					);

				listaEnts.incluir(pPlat);

				if (pGC != NULL) {
					pGC->incluirObstaculo(pPlat);
				}
			}
		}

		void Fase::criarCenario() {
			pJog1 = new Entidades::Personagens::Jogador();

			listaEnts.incluir(pJog1);

			if (pGC != NULL)
			{
				pGC->setJogador(pJog1);
			}

			criarPinguins(); //Criar Inim Faceis
			criarObstaculos();
			criarPlataformas();
			criarInimigos();
		}

		int Fase::gerarQuantidadeAleatoria(const int maximo) const {
			const int minimo = 3;

			if (maximo < minimo) {
				return minimo;
			}

			return minimo + rand() % (maximo - minimo + 1);
		}
	}
}
