#pragma once
#ifndef JOGO_H_
#define JOGO_H_

#include "GerenciadorGrafico.h"
#include "FasePrimeira.h"
#include "Jogador.h"

namespace TrabalhoJogo {

	class Jogo
	{
	private:
		Entidades::Personagens::Jogador* pJog1;
		Gerenciadores::GerenciadorGrafico* pGG;
		Fases::FasePrimeira* faseAtual;

	public:
		Jogo();
		~Jogo();

		void executar();
	};
}
#endif