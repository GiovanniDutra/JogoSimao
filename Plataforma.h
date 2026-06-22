#pragma once

#ifndef PLATAFORMA_H_
#define PLATAFORMA_H_

#include "Obstaculo.h"

namespace TrabalhoJogo {
	namespace Entidades {
		namespace Obstaculos {
			class Plataforma : public Obstaculo {
			private:
				int altura;
				int baseY;
			public:
				Plataforma();
				Plataforma(int x, int y, int largura, int altura); //Sobrecarga para facilitar a criação
				~Plataforma();

				void executar();
				void obstaculizar(Personagens::Jogador* pJogador);
				void salvar();

				virtual void aplicarEmpuxo();
			};
		}
	}
}
#endif

