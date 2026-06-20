#include "EspinhoGelo.h" //Implementado mas so aparece na Fase Dois
#include "Jogador.h"
#include "GerenciadorGrafico.h"

#include <SFML/Graphics.hpp>

namespace TrabalhoJogo {
	namespace Entidades {
		namespace Obstaculos {

			EspinhoGelo::EspinhoGelo() :
				Obstaculo(),
				danosidade(2),
				baseY(0),
				altura(50),
				largura(25)
			{
				danoso = true;

				body.setSize(sf::Vector2f(100.f, 100.f));
				body.setFillColor(sf::Color::Blue);

				if (!carregarTextura("assets/EstacaGelo.png"))
				{
					body.setFillColor(sf::Color::Red);
				}

				setPosicao(0, baseY);
			}

			EspinhoGelo::EspinhoGelo(int x, int y, float largura, float altura) :
				Obstaculo(),
				danosidade(2),
				baseY(y),
				largura(largura),
				altura(altura)
			{
				danoso = true;

				body.setSize(sf::Vector2f(this->largura, this->altura));
				body.setFillColor(sf::Color::Blue);

				if (!carregarTextura("assets/EstacaGelo.png"))
				{
					body.setFillColor(sf::Color::Red);
				}

				setPosicao(x, baseY);
			}

			EspinhoGelo::~EspinhoGelo() {}

			void EspinhoGelo::executar() {} //Falta implementar

			void EspinhoGelo::obstaculizar(Personagens::Jogador* pJogador) {
				if (pJogador == NULL) {
					return;
				}

				sf::FloatRect corpoJogador = pJogador->getBody().getGlobalBounds();
				sf::FloatRect corpoObstaculo = body.getGlobalBounds();

				if (corpoJogador.intersects(corpoObstaculo)) {

					if (danoso) {
						pJogador->receberDano(danosidade);
					}

					if (pJogador->getX() < getX()) {
						pJogador->setPosicao(
							getX() - corpoJogador.width,
							pJogador->getY()
						);
					}
					else {
						pJogador->setPosicao(
							getX() + corpoObstaculo.width,
							pJogador->getY()
						);
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
