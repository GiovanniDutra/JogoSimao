#include "InimMedio.h"
#include "Jogador.h"

#include "SFML/Graphics.hpp"

namespace TrabalhoJogo {
	namespace Entidades {
		namespace Personagens {
			InimMedio::InimMedio() :
				Inimigo(),
				tamanho(45),
				direcao(1),
				limEsq(450),
				limDir(750)
			{
				nivelMaldade = 2;
				num_vidas = 2;

				body.setSize(sf::Vector2f(70.f, 70.f));

				body.setFillColor(sf::Color::Red);

				setPosicao(400, 500);
			}

			InimMedio::InimMedio(int x, int y, int limEsq, int limDir) :
				Inimigo(),
				tamanho(45),
				direcao(1),
				limEsq(limEsq),
				limDir(limDir)
			{
				nivelMaldade = 2;
				num_vidas = 2;

				body.setSize(sf::Vector2f(70.f, 70.f));
				body.setFillColor(sf::Color::Red);

				setPosicao(x, y);
			}

			InimMedio::~InimMedio(){}

			void InimMedio::mover() {
				const int velocidade = 2;

				int novoX = getX() + velocidade * direcao;

				if (novoX < limEsq) {
					novoX = limEsq;
					direcao = 1;
				}
				else if (novoX > limDir) {
					novoX = limDir;
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
