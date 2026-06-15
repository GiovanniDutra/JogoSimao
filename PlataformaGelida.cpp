#include "PlataformaGelida.h"
#include "Jogador.h"

namespace TrabalhoJogo {
	namespace Entidades {
		namespace Obstaculos {
			PlataformaGelida::PlataformaGelida() :
				Obstaculo(),
				largura(30.0f)
			{
				danoso = true;

				body.setSize(sf::Vector2f(largura, largura));
				body.setFillColor(sf::Color::Cyan);

				if (!carregarTextura("assets/boladeneve.png"))
				{
					body.setFillColor(sf::Color::Red);
				}
				
				setPosicao(400, 600);
			}

			PlataformaGelida::PlataformaGelida(int x, int y) :
				Obstaculo(),
				largura(25.0f)
			{
				danoso = true;

				body.setSize(sf::Vector2f(largura, largura));
				body.setFillColor(sf::Color::Cyan);

				if (!carregarTextura("assets/boladeneve.png"))
				{
					body.setFillColor(sf::Color::Red);
				}

				setPosicao(x, y);
			}

			PlataformaGelida::~PlataformaGelida() {}

			void PlataformaGelida::executar() {} //Falta implementar

			void PlataformaGelida::obstaculizar(Personagens::Jogador* pJogador) {
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

			void PlataformaGelida:: salvar() {} //Falta implementar
		}


	}
}
