#pragma once

#ifndef ESPINHOGELO_H_
#define ESPINHOGELO_H_

#include "Obstaculo.h"

namespace TrabalhoJogo {
	namespace Entidades {

		namespace Personagens {
			class Jogador;
		}

		namespace Obstaculos {

			class EspinhoGelo : public Obstaculo
			{
			private:
				short int danosidade;
				
				bool fixado;
				bool aparecendo;

				int contTempo;
				int tempoAlternancia;

				int posFixaX;
				int posFixaY;

				sf::FloatRect getAreaDano() const;
				int getDanosidade() const;
			public:
				EspinhoGelo();
				EspinhoGelo(int x, int y, float largura, float altura);
				~EspinhoGelo();

				void executar();
				void salvar();
				void obstaculizar(Personagens::Jogador* pJogador);
				void salvarDataBuffer();

				void fixarCenario();
				bool estaFixado() const;
				bool estaAparecendo() const;
			};
		}
	}
}
#endif 

