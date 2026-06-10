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
				//int tempoLentidao;
			public:
				ObstMedio();
				ObstMedio(int x, int y); //Sobrecarga para facilitar a criação
				~ObstMedio();

				void executar();
				void salvar();

				void obstaculizar(Personagens::Jogador* pJogador);
			};
		}
	}
}

#endif


