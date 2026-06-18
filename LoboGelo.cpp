#include "LoboGelo.h"
#include "Jogador.h"

#include "SFML/Graphics.hpp"

namespace TrabalhoJogo {
	namespace Entidades {
		namespace Personagens {
			LoboGelo::LoboGelo() :
				Inimigo(),
				tamanho(45),
				direcao(1),
				limEsq(450),
				limDir(750)
			{
				nivelMaldade = 2;
				num_vidas = 2;

				body.setSize(sf::Vector2f(50.f, 40.f));

				body.setFillColor(sf::Color::White);

				if (!carregarTextura("assets/lobopreto.png")) {
					body.setFillColor(sf::Color::Red);
				}

				setPosicao(400, 500);
			}

			LoboGelo::LoboGelo(int x, int y, int limEsq, int limDir) :
				Inimigo(),
				tamanho(45),
				direcao(1),
				limEsq(limEsq),
				limDir(limDir)
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
			
			void LoboGelo::danificar(Jogador* p) {
				if (p != NULL) {
					p->colidir(this);
				}
			}

			void LoboGelo::salvar() {} //Implementar Depois

			void LoboGelo::executar() {
				mover();
				//aplicarGravidade();
			}
		}
	}
}
