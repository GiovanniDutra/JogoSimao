#pragma once
#include "Inimigo.h"

#ifndef PINGUIM_H_
#define PINGUIM_H_


namespace TrabalhoJogo {
	namespace Entidades {
		namespace Personagens {

			class Jogador;

			class Pinguim : public Inimigo
			{
			private:
				int trombada;
				int direcao;
				int limEsq;
				int limDir;
			public:
				Pinguim();
				Pinguim(int x, int y, int limEsq, int limDir); //Sobrecarga
				~Pinguim();

				void executar();
				void danificar(Jogador* p);
				void salvar();
				void mover();


			};
		}
	}
}
#endif

