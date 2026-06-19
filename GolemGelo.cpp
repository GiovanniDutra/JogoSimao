#include "GolemGelo.h"
#include "Jogador.h"

namespace TrabalhoJogo {
	namespace Entidades {
		namespace Personagens {
			GolemGelo::GolemGelo() :
				Inimigo(),
				forca(5),
				direcao(1),
				limEsq(limEsq),
				limDir(limDir)
			{
				nivelMaldade = 3;
				num_vidas = 5;

				body.setSize(sf::Vector2f(150.f, 150.f));
				body.setFillColor(sf::Color::Cyan);

				if (!carregarTextura("assets/GolemGelo.png")) {
					body.setFillColor(sf::Color::Red);
				}

				setPosicao(250, 300);
			}

			GolemGelo::GolemGelo(int x, int y, int limEsq, int limDir) :
				Inimigo(),
				forca(5),
				direcao(1),
				limEsq(limEsq),
				limDir(limDir)
			{
				nivelMaldade = 3;
				num_vidas = 5;

				body.setSize(sf::Vector2f(150.f, 150.f));
				body.setFillColor(sf::Color::Cyan);

				if (!carregarTextura("assets/GolemGelo.png")) {
					body.setFillColor(sf::Color::Red);
				}

				setPosicao(x, y);

			}

			GolemGelo::~GolemGelo(){}

			void GolemGelo::mover() {
				const int velocidade = 4;

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

			void GolemGelo::executar()
			{
				mover();
			}

			void GolemGelo::danificar(Jogador* p)
			{
				if (p != NULL) {
					int dano = nivelMaldade * forca;

					if (dano < 1) {
						dano = 1;
					}

					p->colidir(this);
					p->receberDano(dano);

				}
			}
			void GolemGelo::salvar()
			{
				// Implementar depois
			}
		}
	}
}
