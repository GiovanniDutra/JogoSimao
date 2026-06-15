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

				bool noGelo;
				int tempoGelo;
				int impulsoGelo;
				int ultimaDirecao;

				bool invuneravel;
				int tempInvuneravel;

				void aplicarGravidade();
				void aplicarEscorramento();
				void pular();
				void atualizarInvunerabilidade();
			public:

				Jogador();
				~Jogador();

				void colidir(Inimigo* pInim);

				void executar();
				void salvar();
				void mover();

				void addPontos(int valor);
				int getPontos() const;

				void receberDano();

				int getNumVidas() const;
				bool estarVivo() const;

				void aplicarGelo();

			};
		}
	}
}
#endif




