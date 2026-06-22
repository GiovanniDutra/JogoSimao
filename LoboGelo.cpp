#include "LoboGelo.h"
#include "Jogador.h"

#include "SFML/Graphics.hpp"

namespace TrabalhoJogo {
	namespace Entidades {
		namespace Personagens {
			LoboGelo::LoboGelo() :
				Inimigo(),
				mordida(2),
				forcaPulo(20),
				direcao(1),
				limEsq(300),
				limDir(500),
				velocidade(2),
				puloEspera(90),
				contadorPulo(0)
			{
				nivelMaldade = 2;
				num_vidas = 4;

				body.setSize(sf::Vector2f(50.f, 40.f));

				body.setFillColor(sf::Color::White);

				if (!carregarTextura("assets/lobopreto.png")) {
					body.setFillColor(sf::Color::Red);
				}

				setPosicao(400, 500);
			}

			LoboGelo::LoboGelo(int x, int y, int lE, int lD) :
				Inimigo(),
				mordida(2),
				forcaPulo(20),
				direcao(1),
				limEsq(lE),
				limDir(lD),
				velocidade(2),
				puloEspera(90),
				contadorPulo(0)
			{
				nivelMaldade = 2;
				num_vidas = 2;

				body.setSize(sf::Vector2f(50.f, 40.f));

				body.setFillColor(sf::Color::White);

				if (!carregarTextura("assets/lobopreto.png"))
				{
					body.setFillColor(sf::Color::Red);
				}

				setPosicao(x, y);
			}

			LoboGelo::~LoboGelo(){}

			void LoboGelo::mover() {
				int novoX = getX() + velocidade * direcao;

				if(novoX < limEsq) {
					novoX = limEsq;
					direcao = 1;
				} 
				else if (novoX > limDir) {
					novoX = limDir;
					direcao = -1;
				}

				setPosicao(novoX, getY());
			}
			
			void LoboGelo::danificar(Jogador* p) {
				if (p != NULL) {
					int dano = nivelMaldade * mordida;

					if (dano < 1) {
						dano = 1;
					}

					p->colidir(this);
					p->receberDano(dano);
				}
			}

			void LoboGelo::salvar() {} //Implementar Depois

			void LoboGelo::executar() {
				mover();
				aplicarGravidade();

				if (noChao) {
					velocidadeY = -forcaPulo;
					noChao = false;
					contadorPulo = puloEspera;
				}
				else {
					if(contadorPulo > 0) {
						contadorPulo--;
					}
				}
			}
		}
	}
}
