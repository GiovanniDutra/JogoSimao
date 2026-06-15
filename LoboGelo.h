#pragma once

#ifndef LOBOGELO_H_
#define LOBOGELO_H_

#include "Inimigo.h"

namespace TrabalhoJogo {
	namespace Entidades {
		namespace Personagens {
			class LoboGelo : public Inimigo {
			private:
				int tamanho;
				int direcao;
				int limEsq;
				int limDir;
			public:
				LoboGelo();
				LoboGelo(int x, int y, int limEsq, int limDir); //Sobrecarga
				~LoboGelo();

				virtual void executar();
				virtual void danificar(Jogador* p);
				virtual void salvar();
				virtual void mover();
			};
		}
	}
}

#endif