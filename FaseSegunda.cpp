#include "FaseSegunda.h"
#include "Pinguim.h"
#include "Plataforma.h"
#include "EspinhoGelo.h"
#include "GolemGelo.h"
#include <iostream>
#include "GerenciadorGrafico.h"
#include "Projetil.h"

namespace TrabalhoJogo {
	namespace Fases {

		FaseSegunda::FaseSegunda() : 
			Fase(), 
			maxChefoes(10),
			maxEspinhoGelo(10)
		{
			carregaFundo("assets/cenariofrio2.png");
			criarCenario();
		}

		FaseSegunda::~FaseSegunda() {}

		void FaseSegunda::criarInimigos() {
			criarGolemGelo();
			criarProjeteis();
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
			criarEspinhoGelo();
		}

		void FaseSegunda::criarEspinhoGelo() {
			int quantidade = gerarQuantidadeAleatoria(maxEspinhoGelo);

			int posicoes[10][4] = {
		   {240,  780, 80, 80},
		   {580,  640, 80, 80},
		   {930,  500, 80, 80},
		   {1280, 700, 80, 80},
		   {1580, 560, 80, 80},
		   {350,  420, 80, 80},
		   {720,  300, 80, 80},
		   {1080, 380, 80, 80},
		   {1420, 260, 80, 80},
		   {1660, 760, 80, 80}};

			for (int i = 0; i < quantidade; i++) {
				Entidades::Obstaculos::EspinhoGelo* pEspinho =
					new Entidades::Obstaculos::EspinhoGelo(
						posicoes[i][0],
						posicoes[i][1],
						static_cast<float>(posicoes[i][2]),
						static_cast<float>(posicoes[i][3])
					);

				listaEnts.incluir(pEspinho);

				if (pGC != NULL) {
					pGC->incluirObstaculo(pEspinho);
				}
			}
		}
		void FaseSegunda::criarGolemGelo() {
			int posicoes[10][4] =
			{
				{1300, 300, 1150, 1600},
				{1650, 250, 1450, 1850},
				{900, 400, 750, 1100},
				{1450, 550, 1250, 1750},
				{600, 350, 450, 850},
				{1100, 650, 900, 1400},
				{1750, 650, 1500, 1850},
				{800, 700, 600, 1050},
				{1350, 750, 1100, 1650},
				{500, 650, 350, 750}
			};

			int quantidade = gerarQuantidadeAleatoria(maxChefoes);

			for (int i = 0; i < quantidade; i++)
			{
				int x = posicoes[i][0];
				int y = posicoes[i][1];
				int limEsq = posicoes[i][2];
				int limDir = posicoes[i][3];

				Entidades::Personagens::GolemGelo* pGolem =
					new Entidades::Personagens::GolemGelo(x, y, limEsq, limDir);

				chefes.push_back(pGolem);

				listaEnts.incluir(pGolem);

				if (pGC != NULL)
				{
					pGC->incluirInimigo(pGolem);
				}
			}
		}

		void FaseSegunda::criarProjeteis() {
			for (unsigned int i = 0; i < chefes.size(); i++)
			{
				Entidades::Personagens::GolemGelo* pGolem = chefes[i];

				if (pGolem != NULL)
				{
					Entidades::Projetil* pProjetil = new Entidades::Projetil();

					pGolem->setProjetil(pProjetil);
					pGolem->setAlvo(pJog1);

					listaEnts.incluir(pProjetil);

					if (pGC != NULL)
					{
						pGC->incluirProjetil(pProjetil);
					}
				}
			}
		}
	}
}