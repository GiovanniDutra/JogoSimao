#include "PlataformaGelida.h"
#include "Jogador.h"

namespace TrabalhoJogo {
	namespace Entidades {
		namespace Obstaculos {
			PlataformaGelida::PlataformaGelida() :
				Obstaculo(),
				largura(50.0f),
				altura(25.0f)
			{
				danoso = false;

				body.setSize(sf::Vector2f(largura, altura));
				body.setFillColor(sf::Color::Cyan);

				if (!carregarTextura("assets/plataformaGelida.png"))
				{
					body.setFillColor(sf::Color::Red);
				}
				
				setPosicao(400, 875);
			}

			PlataformaGelida::PlataformaGelida(int x, int y, float largura, float altura) :
				Obstaculo(),
				largura(largura),
				altura(altura)
			{
				danoso = true;

				body.setSize(sf::Vector2f(this->largura, this->altura));
				body.setFillColor(sf::Color::Cyan);

				if (!carregarTextura("assets/plataformaGelida.png"))
				{
					body.setFillColor(sf::Color::Red);
				}

				setPosicao(x, y);
			}

			PlataformaGelida::~PlataformaGelida() {} 

			void PlataformaGelida::executar() {} //Falta implementar

			void PlataformaGelida::obstaculizar(Personagens::Jogador* pJogador) {
				if (pJogador == NULL)
				{
					return;
				}

				sf::FloatRect corpoJogador = pJogador->getBody().getGlobalBounds();
				sf::FloatRect corpoGelo = body.getGlobalBounds();

				if (corpoJogador.intersects(corpoGelo))
				{
					pJogador->aplicarGelo();

					float baseJogador = corpoJogador.top + corpoJogador.height;
					float topoGelo = corpoGelo.top;
					float baseAnterior = baseJogador - pJogador->getVelocidadeY();

					if (pJogador->getVelocidadeY() >= 0 && baseAnterior <= topoGelo)
					{
						pJogador->setPosicao(
							pJogador->getX(),
							static_cast<int>(topoGelo - corpoJogador.height)
						);

						pJogador->zerarVelocidadeY();
						pJogador->setNoChao(true);
					}
				}
			}

			void PlataformaGelida::salvar() {} //Falta implementar
		}
	}
}
