#include "EspinhoGelo.h" //Implementado mas so aparece na Fase Dois
#include "Jogador.h"

#include <SFML/Graphics.hpp>

namespace TrabalhoJogo {
	namespace Entidades {
		namespace Obstaculos {

			EspinhoGelo::EspinhoGelo() :
				Obstaculo(),
				danosidade(2)
			{
				danoso = true;

				body.setSize(sf::Vector2f(100.f, 100.f));
				body.setFillColor(sf::Color::Blue);

				setPosicao(100, 100);
			}

			EspinhoGelo::~EspinhoGelo() {}

			void EspinhoGelo::executar() {} //Falta implementar

			void EspinhoGelo::obstaculizar(Personagens::Jogador* pJogador) {
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
			void EspinhoGelo::salvar()
			{
				//Falta implementar
			}
			void EspinhoGelo::salvarDataBuffer() {
				Entidade::salvarDataBuffer();
			}
		}
	}
}
