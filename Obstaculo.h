#pragma once

#ifndef OSBTACULO_H_
#define OBSTACULO_H_

#include "Entidade.h"

namespace TrabalhoJogo {
	namespace Entidades {
		namespace Personagens { class Jogador;}
		
		namespace Obstaculos {
			class Obstaculo : public Entidade {
			protected:
				bool danoso;
			public:
				Obstaculo();
				~Obstaculo();

				void salvarDataBuffer();

				virtual void executar() = 0;
				virtual void salvar() = 0;
				virtual void obstaculizar(Personagens::Jogador* pJogador) = 0;
			};
		}
	}
}
#endif


