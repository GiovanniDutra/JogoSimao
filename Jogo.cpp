#include "Jogo.h"
#include "Menu.h"
#include "FasePrimeira.h"
#include "FaseSegunda.h"

#include <cstdlib>
#include <ctime>

namespace TrabalhoJogo {

	Jogo::Jogo() :
		pGG(NULL),
		estado(EstadoJogo::JOGANDO),
		faseAtual(NULL)
	{
		srand((unsigned int)time(NULL));

		pGG = new Gerenciadores::GerenciadorGrafico();
		Ente::setGG(pGG);
	}

	Jogo::~Jogo() {
		delete faseAtual;
		delete pGG;
	}

	void Jogo::executar() {
		Menu menu;
		menu.executar();

		if (!menu.deveIniciarJogo())
			return;

		if (menu.getFaseEscolhida() == 1)
			faseAtual = new Fases::FasePrimeira();
		else
			faseAtual = new Fases::FaseSegunda();

		estado = EstadoJogo::JOGANDO;

		while (pGG->janelaAberta()) {

			sf::Event event;
			while (pGG->getJanela().pollEvent(event)) {
				if (event.type == sf::Event::Closed)
					pGG->fecharJanela();

				if (event.type == sf::Event::KeyPressed &&
					event.key.code == sf::Keyboard::Escape) {

					estado = (estado == EstadoJogo::JOGANDO)
						? EstadoJogo::PAUSADO
						: EstadoJogo::JOGANDO;
				}
			}

			pGG->limpar();

			if (estado == EstadoJogo::JOGANDO) {
				if (faseAtual) {
					faseAtual->executar();

					
					if (faseAtual->acabou()) {

						delete faseAtual;
						faseAtual = nullptr;

						if (menu.getFaseEscolhida() == 1) {
							faseAtual = new Fases::FaseSegunda();
						}
						else {
							estado = EstadoJogo::VITORIA;
						}
					}
				}
			}
			else if (estado == EstadoJogo::PAUSADO) {
		
				menu.desenharPausa(pGG->getJanela());
			}
			else if (estado == EstadoJogo::MORREU) {
				//menu.executarGameOver();
			}
			else if (estado == EstadoJogo::VITORIA)
			{
				menu.desenharTelaVitoria(pGG->getJanela());
			}

			pGG->mostrar();
		}

	}
}
