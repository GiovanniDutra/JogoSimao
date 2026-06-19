#pragma

#ifndef JOGO_H_
#define JOGO_H_

#include "GerenciadorGrafico.h"
#include "FasePrimeira.h"
#include "FaseSegunda.h"
#include "Jogador.h"
#include "Menu.h"


namespace TrabalhoJogo {

	class Jogo
	{
	private:
		Entidades::Personagens::Jogador* pJog1;
		Gerenciadores::GerenciadorGrafico* pGG;
		Fases::Fase* faseAtual;

		sf::RenderWindow window;

	public:
		Jogo();
		~Jogo();

		void executar();
	};
}
#endif