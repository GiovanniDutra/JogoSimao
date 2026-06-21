#include "GolemGelo.h"
#include "Jogador.h"
#include "Projetil.h"

#include <cmath>

namespace TrabalhoJogo {
	namespace Entidades {
		namespace Personagens {
			GolemGelo::GolemGelo() :
				Inimigo(),
				forca(5),
				direcao(1),
				limEsq(0),
				limDir(0),
				jaAtirou(false),
				pProjetil(NULL),
				pAlvo(NULL)
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

			GolemGelo::GolemGelo(int x, int y, int lE, int lD) :
				Inimigo(),
				forca(5),
				direcao(1),
				limEsq(lE),
				limDir(lD),
				jaAtirou(false),
				pProjetil(NULL),
				pAlvo(NULL)
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

			GolemGelo::~GolemGelo(){
				pProjetil = NULL;
				pAlvo = NULL;
			}

			void GolemGelo::mover() {
				const int velocidade = 1;

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
				aplicarGravidade();

				if (!jaAtirou) {
					atirar();
				}
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

			void GolemGelo::setProjetil(Projetil* pP) {
				pProjetil = pP;

				if (pP != NULL) {
					pP->setDono(this);
				}
			}

			void GolemGelo::setAlvo(Jogador* pJogador) {
				pAlvo = pJogador;
			}

			void GolemGelo::atirar() {
				if (jaAtirou || pProjetil == NULL || pAlvo == NULL) {
					return;
				}

				sf::Vector2f posicao((float)getX(), (float)getY());
				sf::Vector2f direcao;

				if (pAlvo->getX() < getX())
				{
					direcao.x = -1.0f;
				}
				else
				{
					direcao.x = 1.0f;
				}

				direcao.y = 0.0f;

				pProjetil->prepararDisparo(posicao, direcao);

				jaAtirou = true;
			}
		}
	}
}
