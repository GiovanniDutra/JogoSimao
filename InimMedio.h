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
			public:
				InimMedio();
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