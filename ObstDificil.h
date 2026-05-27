#pragma once

#ifndef OBSTDIFICIL_H_
#define OBSTDIFICIL_H_

#include "Obstaculo.h"

namespace TrabalhoJogo {
	namespace Entidades {

		namespace Personagens {
			class Jogador;
		}

		namespace Obstaculos {

			class ObstDificil : public Obstaculo
			{
			private:
				short int danosidade;

			public:
				ObstDificil();
				virtual ~ObstDificil();

				void executar();
				void salvar();
				void obstaculizar(Personagens::Jogador* pJogador);
				void salvarDataBuffer();
			};
		}
	}
}
#endif 

