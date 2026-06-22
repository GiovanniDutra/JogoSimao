#pragma once

#ifndef PLATAFORMAGELIDA_H_
#define PLATAFORMAGELIDA_H_

#include "Obstaculo.h"
#include "Jogador.h"

namespace TrabalhoJogo {
	namespace Entidades {
		namespace Obstaculos {
			class PlataformaGelida : public Obstaculo {
			private:
				float largura;
				float altura;

				int escorregamento;
				int direcaoEscorregamento;

				int baseY;
				int empuxo;
			public:
				PlataformaGelida();
				PlataformaGelida(int x, int y, float largura, float altura); //Sobrecarga para facilitar a criação
				~PlataformaGelida();

				void executar();
				void salvar();

				void obstaculizar(Personagens::Jogador* pJogador);

				virtual void aplicarEmpuxo();
			};
		}
	}
}

#endif


