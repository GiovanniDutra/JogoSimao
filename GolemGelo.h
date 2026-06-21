#pragma once

#ifndef GOLEMGELO_H_
#define GOLEMGELO_H_

#include "Inimigo.h"

namespace TrabalhoJogo {
	namespace Entidades {
		
		class Projetil;

		namespace Personagens {
			class Jogador;

			class GolemGelo : public Inimigo {
			private:
				int direcao;

				int limEsq;
				int limDir;

				short int forca;

				bool jaAtirou;

				Projetil* pProjetil;
				Jogador* pAlvo;
			public:
				GolemGelo();
				GolemGelo(int x, int y, int limEsq, int limDir);
				~GolemGelo();

				void executar();
				void danificar(Jogador* p);
				void salvar();
				void mover();

				void setProjetil(Projetil* pP);
				void setAlvo(Jogador* pJogador);
				void atirar();
			};
		}
	}
}

#endif
