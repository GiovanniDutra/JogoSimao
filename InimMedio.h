#pragma once

#ifndef INIMMEDIO_H_
#define INIMMEDIO_H_

#include "Inimigo.h"

namespace TrabalhoJogo {
	namespace Entidades {
		namespace Personagens {
			class InimMedio : public Inimigo {
			private:
				int tamanho;
				int direcao;
				int limEsq;
				int limDir;
			public:
				InimMedio();
				InimMedio(int x, int y, int limEsq, int limDir); //Sobrecarga
				~InimMedio();

				virtual void executar();
				virtual void danificar(Jogador* p);
				virtual void salvar();
				virtual void mover();
			};
		}
	}
}

#endif