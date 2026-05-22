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
				private:
					int pontos;

				public:

					Jogador();
					virtual ~Jogador();

					void colidir(Inimigo* inimigo);
					virtual void executar();
					virtual void salvar();
					virtual void mover();

					void addPontos(int valor);
					int getPontos() const;

				};
		}
	}
}
#endif




