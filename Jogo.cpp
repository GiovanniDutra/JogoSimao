#include "Jogo.h"

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
<<<<<<< HEAD
	
=======
>>>>>>> 241329947601a0d9eef8df0610e2b59093c258e6
	Jogo::~Jogo() {} //Implementar depois

	void Jogo::executar()
	{
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
<<<<<<< HEAD
}
=======
}
>>>>>>> 241329947601a0d9eef8df0610e2b59093c258e6
