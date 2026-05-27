#include "InimFacil.h"
#include "Jogador.h"

namespace TrabalhoJogo {
	namespace Entidades {
		namespace Personagens {

			InimFacil::InimFacil() : 
				Inimigo(),
				raio(20.0),
				direcao(1)
			{
				nivelMaldade = 1;
				num_vidas = 1;

				body.setSize(sf::Vector2f(100.f, 100.f));
				body.setFillColor(sf::Color::Green);

				setPosicao(200, 200);
			}
			InimFacil::~InimFacil() {}

			void InimFacil::mover() {
				const int velocidade = 4;

				int novoX = getX() + velocidade * direcao;

				if (novoX < 250) {
					novoX = 250;
					direcao = 1;
				}
				else if (novoX > 400) {
					novoX = 400;
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