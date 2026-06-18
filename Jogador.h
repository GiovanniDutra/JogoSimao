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

				bool invuneravel;
				int tempInvuneravel;

				bool atacando;
				int tempoAtacando;
				int duracaoAtaque;
				int intervaloAtaqueCont;
				int intervaloAtaque;
				int forca;
				int direcao;

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

				void receberDano(int dano);

				int getNumVidas() const;
				bool estarVivo() const;

				void atacar();
				bool estaAtacando() const;
				int getForcaAtaque() const;
				int getDirecaoAtaque() const;
			};
		}
	}
}
#endif




