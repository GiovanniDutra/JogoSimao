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
			int quantidade = gerarQuantidadeAleatoria(maxChefoes);

			int posicoes[10][4] = {
			{650,  605, 600, 760},
			{560,  415, 500, 700},
			{940,  315, 880, 1100},
			{1250, 620, 1180, 1440},
			{1520, 450, 1460, 1740},
			{300,  720, 220, 500},
			{780,  680, 700, 960},
			{1080, 500, 1000, 1280},
			{1380, 350, 1300, 1580},
			{1600, 760, 1520, 1840}};

			for (int i = 0; i < quantidade; i++)
			{
				Entidades::Personagens::GolemGelo* pGolem =
					new Entidades::Personagens::GolemGelo(
						posicoes[i][0],
						posicoes[i][1],
						posicoes[i][2],
						posicoes[i][3]
					);

				Entidades::Projetil* pProjetil = new Entidades::Projetil();

				pGolem->setProjetil(pProjetil);
				pGolem->setAlvo(pJog1);

				listaEnts.incluir(pGolem);
				listaEnts.incluir(pProjetil);

				if (pGC != NULL)
				{
					pGC->incluirInimigo(pGolem);
					pGC->incluirProjetil(pProjetil);
				}
			}
		}
	}
}