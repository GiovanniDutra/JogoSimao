#pragma once

#ifndef CHEFAO_H_
#define CHEFAO_H_

#include "Inimigo.h"

namespace TrabalhoJogo {
	namespace Entidades {
		namespace Personagens {
			class Chefao : public Inimigo {
			private:
				int direcao;
				short int forca;
			public:
				Chefao();
				~Chefao();

				void executar();
				void danificar(Jogador* p);
				void salvar();
				void mover();
			};
		}
	}
}

#endif

