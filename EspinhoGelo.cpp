#include "EspinhoGelo.h"
#include "Jogador.h"

namespace TrabalhoJogo {
	namespace Entidades {
		namespace Obstaculos {

			EspinhoGelo::EspinhoGelo() :
				Obstaculo(),
				danosidade(2),
				fixado(false),
				aparecendo(true),
				contTempo(0),
				tempoAlternancia(180),
				posFixaX(0),
				posFixaY(0)
			{
				danoso = true;

				body.setSize(sf::Vector2f(70.f, 80.f));
				body.setFillColor(sf::Color::Black);

				if (!carregarTextura("assets/EstacaGelo.png"))
				{
					body.setFillColor(sf::Color::Red);
				}

				setPosicao(0, 0);
			}

			EspinhoGelo::EspinhoGelo(int x, int y, float largura, float altura) :
				Obstaculo(),
				danosidade(2),
				fixado(false),
				aparecendo(true),
				contTempo(0),
				tempoAlternancia(120),
				posFixaX(x),
				posFixaY(y)
			{
				danoso = true;

				body.setSize(sf::Vector2f(largura, altura));
				body.setFillColor(sf::Color::White);

				if (!carregarTextura("assets/EstacaGelo.png"))
				{
					body.setFillColor(sf::Color::Red);
				}

				setPosicao(x, y);
			}

			EspinhoGelo::~EspinhoGelo() {}

			void EspinhoGelo::executar() {
				if (!fixado) {
					aplicarGravidade();
					return;
				}

				contTempo++;

				if (contTempo >= tempoAlternancia) {
					contTempo = 0;
					aparecendo = !aparecendo;

					if (aparecendo) {
						setPosicao(posFixaX, posFixaY);
					}
					else {
						setPosicao(-1000, -1000);
					}
				}
			}

			void EspinhoGelo::obstaculizar(Personagens::Jogador* pJogador) {
				if (pJogador == NULL || !fixado || !aparecendo) {
					return;
				}

				if (getAreaDano().intersects(pJogador->getBody().getGlobalBounds())) {
					if (danoso) {
						pJogador->receberDano(danosidade);
					}
				}
			}
			void EspinhoGelo::salvar()
			{
				//Falta implementar
			}

			void EspinhoGelo::salvarDataBuffer() {} //Falta Implementar

			void EspinhoGelo::fixarCenario() {
				fixado = true;
				aparecendo = true;
				contTempo = 0;

				posFixaX = getX();
				posFixaY = getY();

				zerarVelocidadeY();
				setNoChao(true);
				setPosicao(posFixaX, posFixaY);
			}

			bool EspinhoGelo::estaFixado() const {
				return fixado;
			}

			bool EspinhoGelo::estaAparecendo() const {
				return aparecendo;
			}

			sf::FloatRect EspinhoGelo::getAreaDano() const {
				sf::FloatRect area = body.getGlobalBounds();

				area.left -= 5.0f;
				area.top -= 8.0f;
				area.width += 10.0f;
				area.height += 13.0f;

				return area;
			}

			int EspinhoGelo::getDanosidade() const {
				return danosidade;
			}
		}
	}
}
