#include "ObstDificil.h"
#include "Jogador.h"

namespace TrabalhoJogo {
	namespace Entidades {
		namespace Obstaculos {

			ObstDificil::ObstDificil() :
				Obstaculo(),
				danosidade(2)
			{
				danoso = true;

				body.setSize(sf::Vector2f(200.f, 60.f));
				body.setFillColor(sf::Color::Blue);
				body.setOutlineColor(sf::Color::White);
				body.setOutlineThickness(4.f);

				setPosicao(100, 100);
			}

			ObstDificil::~ObstDificil() {}

			void ObstDificil::executar() {
				desenhar();
			}

			void ObstDificil::obstaculizar(Personagens::Jogador* pJogador) {
				if (!pJogador)
					return;

				sf::FloatRect corpoJogador = pJogador->getBody().getGlobalBounds();
				sf::FloatRect corpoObst = body.getGlobalBounds();

				if (corpoJogador.intersects(corpoObst)) {
					pJogador->receberDano();
				}
			}
			void ObstDificil::salvar()
			{

			}
			void ObstDificil::salvarDataBuffer() {
				Entidade::salvarDataBuffer();
			}
		}
	}
}