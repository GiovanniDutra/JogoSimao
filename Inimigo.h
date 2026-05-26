#pragma once

#ifndef INIMIGO_H_
#define INIMIGO_H_

#include "Personagem.h"

namespace TrabalhoJogo {
	namespace Entidades {
		namespace Personagens {
			class Jogador;

			class Inimigo : public Personagem {
			protected:
				int nivelMaldade;
			public:
				Inimigo();
				~Inimigo();

				void salvarDataBuffer();

				virtual void executar() = 0;
				virtual void danificar(Jogador* p) = 0;
				virtual void salvar() = 0;
			};
		}
	}
}

#endif

