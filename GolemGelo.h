#pragma once

#ifndef GOLEMGELO_H_
#define GOLEMGELO_H_

#include "Inimigo.h"

namespace TrabalhoJogo {
	namespace Entidades {
		namespace Personagens {
			class GolemGelo : public Inimigo {
			private:
				int direcao;
				int limEsq;
				int limDir;
				short int forca;
			public:
				GolemGelo();
				GolemGelo(int x, int y, int limEsq, int limDir);
				~GolemGelo();

				void executar();
				void danificar(Jogador* p);
				void salvar();
				void mover();
			};
		}
	}
}

#endif
