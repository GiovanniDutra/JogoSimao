#include "InimMedio.h"
#include "Jogador.h"

#include "SFML/Graphics.hpp"

namespace TrabalhoJogo {
	namespace Entidades {
		namespace Personagens {
			InimMedio::InimMedio() :
				Inimigo(),
				tamanho(45),
				direcao(1)
			{
				nivelMaldade = 2;
				num_vidas = 2;

				body.setSize(sf::Vector2f(100.f, 100.f));

				body.setFillColor(sf::Color::Red);

				setPosicao(400, 300);
			}

			InimMedio::~InimMedio(){}

			void InimMedio::mover() {
				const int velocidade = 2;

				int novoX = getX() + velocidade * direcao;

				if (novoX < 450) {
					novoX = 450;
					direcao = 1;
				}
				else if (novoX > 750) {
					novoX = 750;
					direcao = -1;
				}

				setPosicao(novoX, getY());
			}

			void InimMedio::danificar(Jogador* p) {
				if (p != NULL) {
					p->colidir(this);
				}
			}

			void InimMedio::salvar() {} //Implementar Depois

			void InimMedio::executar() {
				mover();
			}
		}
	}
}
