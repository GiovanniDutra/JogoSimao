#pragma once

#ifndef JOGADOR_H_
#define JOGADOR_H_

#include "Personagem.h"

namespace TrabalhoJogo {
	namespace Entidades {
		namespace Personagens {

			class Inimigo;

			class Jogador : public Personagem
			{
			protected:
				int pontos;

			public:

				Jogador();
				~Jogador();

				void colidir(Inimigo* inimigo);

				void executar();
				void salvar();
				void mover();

				void addPontos(int valor);
				int getPontos() const;

			};
		}
	}
}
#endif




