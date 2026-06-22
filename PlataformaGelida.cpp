#include "PlataformaGelida.h"
#include "Jogador.h"

namespace TrabalhoJogo {
	namespace Entidades {
		namespace Obstaculos {
			PlataformaGelida::PlataformaGelida() :
				Obstaculo(),
				largura(50.0f),
				altura(25.0f),
				escorregamento(3),
				direcaoEscorregamento(1),
				baseY(0),
				empuxo(1.0f)
			{
				danoso = false;

				body.setSize(sf::Vector2f(largura, altura));
				body.setFillColor(sf::Color::Cyan);

				if (!carregarTextura("assets/plataformaGelida.png"))
				{
					body.setFillColor(sf::Color::Red);
				}
				
				setPosicao(0, baseY);
			}

			PlataformaGelida::PlataformaGelida(int x, int y, float largura, float altura) :
				Obstaculo(),
				largura(largura),
				altura(altura),
				escorregamento(3),
				direcaoEscorregamento(1),
				baseY(y),
				empuxo(1.0f)
			{
				danoso = false;

				body.setSize(sf::Vector2f(this->largura, this->altura));
				body.setFillColor(sf::Color::Cyan);

				if (!carregarTextura("assets/plataformaGelida.png"))
				{
					body.setFillColor(sf::Color::Red);
				}

				setPosicao(x, baseY);
			}

			PlataformaGelida::~PlataformaGelida() {} 

			void PlataformaGelida::executar() {
				aplicarGravidade();
				aplicarEmpuxo();
			}

			void PlataformaGelida::obstaculizar(Personagens::Jogador* pJogador) {
				if (pJogador == NULL)
				{
					return;
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
					direcaoEscorregamento = 1;
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
					direcaoEscorregamento = -1;
				}

				if (direcaoEscorregamento != 0) {
					pJogador->setPosicao(
						pJogador->getX() + direcaoEscorregamento * escorregamento,
						pJogador->getY());
				}
			}

			void PlataformaGelida::salvar() {} //Falta implementar

			void PlataformaGelida::aplicarEmpuxo() {
				Entidade::aplicarGravidade();

				int forcaEmpuxo = getY() - baseY;

				setPosicao(getX(), getY() - forcaEmpuxo);

				zerarVelocidadeY();
				setNoChao(true);;
			}
		}
	}
}
