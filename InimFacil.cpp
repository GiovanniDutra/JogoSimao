#include "InimFacil.h"
#include "Jogador.h"

namespace TrabalhoJogo {
	namespace Entidades {
		namespace Personagens {

			InimFacil::InimFacil() :
				Inimigo(),
				raio(20.0),
				direcao(1),
				limEsq(200),
				limDir(400)
			{
				nivelMaldade = 1;
				num_vidas = 1;

				body.setSize(sf::Vector2f(100.f, 80.f));

				body.setFillColor(sf::Color::White);

				if (!carregarTextura("assets/pinguim.png")) {
					body.setFillColor(sf::Color::Red);
				}

				setPosicao(250, 620);
			}

			InimFacil::InimFacil(int x, int y, int limEsq, int limDir) :
				Inimigo(),
				raio(20.0),
				direcao(1),
				limEsq(limEsq),
				limDir(limDir)
			{
				nivelMaldade = 1;
				num_vidas = 1;
				body.setSize(sf::Vector2f(100.f, 80.f));

				body.setFillColor(sf::Color::White);

				if (!carregarTextura("assets/pinguim.png"))
				{
					body.setFillColor(sf::Color::Red);
				}

				setPosicao(x, y);
			}

			InimFacil::~InimFacil() {}

			void InimFacil::mover() {
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

			void InimFacil::executar()
			{
				mover();
			}
			
			void InimFacil::danificar(Jogador* p)
			{
				if (p != NULL) {
					p->colidir(this);
				}
			}

			void InimFacil::salvar() {
				//Falta implementar
			}
		}
	}
}