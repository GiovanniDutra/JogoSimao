#include "FasePrimeira.h"
#include "LoboGelo.h"
#include "PlataformaGelida.h"
#include <iostream>
#include "GerenciadorGrafico.h"

namespace TrabalhoJogo {
	namespace Fases {
		FasePrimeira::FasePrimeira() :
			Fase(),
			maxLoboGelo(10),
			maxPlataformasGelidas(10)
		{
			carregaFundo("assets/cenariofrio.jfif");
			criarCenario();
		}

		FasePrimeira::~FasePrimeira() {}

		void FasePrimeira::criarInimigos() {
			criarLoboGelo();
		}

		void FasePrimeira::criarObstaculos() {
			criarPlataformasGelidas();
		}

		void FasePrimeira::carregaFundo(const std::string& caminho)
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

		void FasePrimeira::criarLoboGelo() {
			int quantidade = gerarQuantidadeAleatoria(maxLoboGelo);

			int posicoes[10][4] = {
			{650,  605, 580, 820},
			{560,  415, 520, 730},
			{940,  315, 880, 1100},
			{1250, 620, 1180, 1440},
			{1550, 440, 1480, 1740},
			{300,  760, 220, 500},
			{720,  690, 640, 900},
			{1080, 520, 1000, 1260},
			{1360, 350, 1300, 1540},
			{1620, 760, 1540, 1840}};

			for (int i = 0; i < quantidade; i++) {
				Entidades::Personagens::LoboGelo* pLobo =
					new Entidades::Personagens::LoboGelo(
						posicoes[i][0],
						posicoes[i][1],
						posicoes[i][2],
						posicoes[i][3]
					);	

				listaEnts.incluir(pLobo);

				if (pGC != NULL) {
					pGC->incluirInimigo(pLobo);
				}
			}
		}

		void FasePrimeira::criarPlataformasGelidas() {
			int quantidade = gerarQuantidadeAleatoria(maxPlataformasGelidas);

			int posicoes[10][4] = {
		   {260,  760, 300, 45},
		   {620,  630, 300, 45},
		   {980,  480, 300, 45},
		   {1360, 650, 300, 45},
		   {1480, 430, 300, 45},
		   {120,  560, 280, 45},
		   {520,  390, 280, 45},
		   {900,  250, 280, 45},
		   {1260, 340, 280, 45},
		   {1620, 720, 250, 45}};

			for (int i = 0; i < quantidade; i++) {
				Entidades::Obstaculos::PlataformaGelida* pGelida =
					new Entidades::Obstaculos::PlataformaGelida(
						posicoes[i][0],
						posicoes[i][1],
						static_cast<float>(posicoes[i][2]),
						static_cast<float>(posicoes[i][3])
					);

				listaEnts.incluir(pGelida);

				if (pGC != NULL) {
					pGC->incluirObstaculo(pGelida);
				}
			}
		}
		bool FasePrimeira::jogadorVivo() const {
			return pJog1 && pJog1->estarVivo();
		}
	}
}
