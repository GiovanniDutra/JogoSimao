#include "Jogo.h"
#include "Menu.h"
#include "FasePrimeira.h"
#include "FaseSegunda.h"

#include <cstdlib>
#include <ctime>

namespace TrabalhoJogo {

	Jogo::Jogo() :
		pGG(NULL),
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

		while (pGG->janelaAberta()) {
			pGG->tratarEventos();
			pGG->limpar();

			faseAtual->executar();

			pGG->mostrar();
		
		}
	}
}