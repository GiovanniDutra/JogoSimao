#include "ObstMedio.h"
#include "Jogador.h"

namespace TrabalhoJogo {
	namespace Entidades {
		namespace Obstaculos {
			ObstMedio::ObstMedio() :
				Obstaculo(),
				largura(50.0f)
			{
				danoso = true;

				body.setSize(sf::Vector2f(largura, 50.f));
				body.setFillColor(sf::Color::Cyan);
				
				setPosicao(400, 600);

				if (!carregarTextura("assets/boladeneve.png")) {
					body.setFillColor(sf::Color::Blue);
				}
			}

			ObstMedio::ObstMedio(int x, int y) :
				Obstaculo(),
				largura(50.0f)
			{
				danoso = true;

				body.setSize(sf::Vector2f(largura, 50.0f));
				body.setFillColor(sf::Color::Cyan);

				setPosicao(x, y);

				if (!carregarTextura("assets/boladeneve.png")) {
					body.setFillColor(sf::Color::Blue);
				}
			}

			ObstMedio::~ObstMedio() {}

			void ObstMedio::executar() {} //Falta implementar

			void ObstMedio::obstaculizar(Personagens::Jogador* pJogador) {
				if(pJogador == NULL) {
					return;
				}

				sf::FloatRect corpoJogador = pJogador->getBody().getGlobalBounds();
				sf::FloatRect corpoObstaculo = body.getGlobalBounds();

				if(corpoJogador.intersects(corpoObstaculo)) {
					if (danoso) {
						pJogador->receberDano();
					}

					if(pJogador->getX() < getX()) {
						pJogador->setPosicao(getX() - corpoJogador.width, pJogador->getY());
					} 
					else {
						pJogador->setPosicao(getX() + corpoObstaculo.width, pJogador->getY());
					}
				}
			}

			void ObstMedio:: salvar() {} //Falta implementar
		}


	}
}
