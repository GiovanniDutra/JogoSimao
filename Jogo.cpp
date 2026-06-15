#include "Jogo.h"
#include "Menu.h"

namespace TrabalhoJogo {
	Jogo::Jogo() :
		pJog1(NULL),
		pGG(NULL),
		faseAtual(NULL)
	{
		pGG = new Gerenciadores::GerenciadorGrafico();
		Ente::setGG(pGG);

		faseAtual = new Fases::FasePrimeira();
	}
	Jogo::~Jogo() {} //Implementar depois

	void Jogo::executar()
	{
		Menu menu;
		menu.run_menu();

		pGG = new Gerenciadores::GerenciadorGrafico();
		Ente::setGG(pGG);
		faseAtual = new Fases::FasePrimeira();

		while (pGG->janelaAberta())
		{
			pGG->tratarEventos();
			pGG->limpar();

			if (faseAtual)
			{
				faseAtual->executar();
			}
			pGG->mostrar();
		}
	}
}
