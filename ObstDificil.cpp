#include "ObstDificil.h" //Implementado mas so aparece na Fase Dois
#include "Jogador.h"

#include <SFML/Graphics.hpp>

namespace TrabalhoJogo {
	namespace Entidades {
		namespace Obstaculos {

			ObstDificil::ObstDificil() :
				Obstaculo(),
				danosidade(2)
			{
				danoso = true;

				body.setSize(sf::Vector2f(100.f, 100.f));
				body.setFillColor(sf::Color::Blue);

				setPosicao(100, 100);
			}

			ObstDificil::~ObstDificil() {}

			void ObstDificil::executar() {} //Falta implementar

			void ObstDificil::obstaculizar(Personagens::Jogador* pJogador) {
				if (!pJogador)
					return;

				sf::FloatRect corpoJogador = pJogador->getBody().getGlobalBounds();
				sf::FloatRect corpoObstaculo = body.getGlobalBounds();

				if (corpoJogador.intersects(corpoObstaculo)) {
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
			void ObstDificil::salvar()
			{
				//Falta implementar
			}
			void ObstDificil::salvarDataBuffer() {
				Entidade::salvarDataBuffer();
			}
		}
	}
}
