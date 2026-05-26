#pragma once

#ifndef OBSTMEDIO_H_
#define OBSTMEDIO_H_

#include "Obstaculo.h"

namespace TrabalhoJogo {
	namespace Entidades {
		namespace Obstaculos {
			class ObstMedio : public Obstaculo {
			private:
				float largura;
			public:
				ObstMedio();
				~ObstMedio();

				void executar();

				void obstaculizar(Personagens::Jogador* pJogador);
			};
		}
	}
}

#endif


