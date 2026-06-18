#include "Pinguim.h"
#include "Jogador.h"

namespace TrabalhoJogo {
	namespace Entidades {
		namespace Personagens {

			Pinguim::Pinguim() :
				Inimigo(),
				raio(20.0),
				direcao(1),
				limEsq(200),
				limDir(400)
			{
				nivelMaldade = 1;
				num_vidas = 1;

				body.setSize(sf::Vector2f(50.f, 40.f));

				body.setFillColor(sf::Color::White);

				if (!carregarTextura("assets/pinguim.png")) {
					body.setFillColor(sf::Color::Red);
				}

				setPosicao(250, 620);
			}

			Pinguim::Pinguim(int x, int y, int limEsq, int limDir) :
				Inimigo(),
				raio(20.0),
				direcao(1),
				limEsq(limEsq),
				limDir(limDir)
			{
				nivelMaldade = 1;
				num_vidas = 1;
				body.setSize(sf::Vector2f(50.f, 40.f));

				body.setFillColor(sf::Color::White);

				if (!carregarTextura("assets/pinguim.png"))
				{
					body.setFillColor(sf::Color::Red);
				}

				setPosicao(x, y);
			}

			Pinguim::~Pinguim() {}

			void Pinguim::mover() {
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

			void Pinguim::executar()
			{
				mover();
				//aplicarGravidade();
			}
			
			void Pinguim::danificar(Jogador* p)
			{
				if (p != NULL) {
					p->colidir(this);
				}
			}

			void Pinguim::salvar() {
				//Falta implementar
			}
		}
	}
}