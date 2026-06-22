#include "Plataforma.h"
#include "Jogador.h"

namespace TrabalhoJogo {
	namespace Entidades {
		namespace Obstaculos {
			Plataforma::Plataforma() :
				Obstaculo(),
				altura(40),
				baseY(700)
			{
				danoso = false;

				body.setSize(sf::Vector2f(1300.0f, 25.f));
				body.setFillColor(sf::Color::White);

				if (!carregarTextura("assets/plataforma.png")) {
					body.setFillColor(sf::Color::Red);
				}

				setPosicao(0, baseY);
			}

			Plataforma::Plataforma(int x, int y, int largura, int alt) :
				Obstaculo(),
				altura(alt),
				baseY(y)
			{
				danoso = false;

				body.setSize(sf::Vector2f(static_cast<float>(largura),
					static_cast<float>(altura)));

				body.setFillColor(sf::Color::White);

				if (!carregarTextura("assets/plataforma.png")) {
					body.setFillColor(sf::Color::Red);
				}

				setPosicao(x, baseY);
			}

			Plataforma::~Plataforma(){}

			void Plataforma::executar() {
				aplicarGravidade();
				aplicarEmpuxo();
			}

			void Plataforma::obstaculizar(Personagens::Jogador* pJogador) {
				if (pJogador == 0) {
					return;
				}

				sf::FloatRect corpoJogador = pJogador->getBody().getGlobalBounds();
				sf::FloatRect corpoPlataforma = body.getGlobalBounds();

				if (corpoJogador.intersects(corpoPlataforma)) {
					float baseJogador = corpoJogador.top + corpoJogador.height;
					float topoPlataforma = corpoPlataforma.top;
					float baseAnterior = baseJogador - pJogador->getVelocidadeY();

					if (pJogador->getVelocidadeY() >= 0 && baseAnterior <= topoPlataforma) {
						pJogador->setPosicao(pJogador->getX(), static_cast<int>(topoPlataforma - corpoJogador.height));
					}

					pJogador->zerarVelocidadeY();
					pJogador->setNoChao(true);
				}
			}

			void Plataforma::salvar() {
				salvarDataBuffer();
			}

			void Plataforma::aplicarEmpuxo() {
				Entidade::aplicarGravidade();

				int forcaEmpuxo = getY() - baseY;

				setPosicao(getX(), getY() - forcaEmpuxo);

				zerarVelocidadeY();
				setNoChao(true);
			}
		}
	}
}
