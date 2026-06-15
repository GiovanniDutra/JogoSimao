#pragma once

#ifndef PLATAFORMAGELIDA_H_
#define PLATAFORMAGELIDA_H_

#include "Obstaculo.h"

namespace TrabalhoJogo {
	namespace Entidades {
		namespace Obstaculos {
			class PlataformaGelida : public Obstaculo {
			private:
				float largura;
				//int tempoLentidao;
			public:
				PlataformaGelida();
				PlataformaGelida(int x, int y); //Sobrecarga para facilitar a criação
				~PlataformaGelida();

				void executar();
				void salvar();

				void obstaculizar(Personagens::Jogador* pJogador);
			};
		}
	}
}

#endif


