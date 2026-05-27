#pragma once

#ifndef JOGADOR_H_
#define JOGADOR_H_

#include "Personagem.h"

namespace TrabalhoJogo {
	namespace Entidades {
		namespace Personagens {

			class Inimigo;

			class Jogador : public Personagem
			{
			protected:
				int pontos;
				int velocidadeY;
				bool noChao;

				bool invuneravel;
				int tempInvuneravel;

				void aplicarGravidade();
				void pular();
				void atualizarInvunerabilidade();
			public:

				Jogador();
				~Jogador();

				void colidir(Inimigo* pInim);

				int getVelocidadeY() const;
				void zerarVelocidadeY();
				void setNoChao(bool estado);

				void executar();
				void salvar();
				void mover();

				void addPontos(int valor);
				int getPontos() const;

				void receberDano();

			};
		}
	}
}
#endif




