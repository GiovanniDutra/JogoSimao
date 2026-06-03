#include "Jogador.h"
#include "Inimigo.h"

#include "SFML/Graphics.hpp"

namespace TrabalhoJogo {
	namespace Entidades {
		namespace Personagens {

			Jogador::Jogador():
				Personagem(),
				pontos(0),
				velocidadeY(0),
				noChao(false),
				invuneravel(false),
				tempInvuneravel(0)
			{
				num_vidas = 5;

				body.setSize(sf::Vector2f(100.f, 100.f));
				body.setFillColor(sf::Color::White);

				setPosicao(50, 300);
			}

			Jogador::~Jogador() {}

			void Jogador::executar()
			{
				mover();
				aplicarGravidade();
				atualizarInvunerabilidade();
			}

			void Jogador::salvar() {}

			void Jogador::mover()
			{
				const int velocidadeX = 5;

				int novoX = getX();

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				{
					novoX -= velocidadeX;
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				{
					novoX += velocidadeX;
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					pular();
				}

				setPosicao(novoX, getY());
			}

			void Jogador::colidir(Inimigo* pInim)
			{
				if (pInim != NULL)
				{
					receberDano();
				}
			}

			void Jogador::pular() {
				if (noChao)
				{
					velocidadeY = -15;
					noChao = false;
				}
			}

			void Jogador::aplicarGravidade() {
				const int gravidade = 1;
				const int velocidadeMaxima = 20;

				velocidadeY += gravidade;

				if (velocidadeY > velocidadeMaxima)
				{
					velocidadeY = velocidadeMaxima;
				}

				noChao = false;

				setPosicao(getX(), getY() + velocidadeY);
			}

			int Jogador::getVelocidadeY() const {
				return velocidadeY;
			}

			void Jogador::zerarVelocidadeY() {
				velocidadeY = 0;
			}

			void Jogador::setNoChao(bool estado) {
				noChao = estado;
			}

			void Jogador::addPontos(int valor) {
				pontos += valor;
			}

			int Jogador::getPontos() const {
				return pontos;
			}

			void Jogador::atualizarInvunerabilidade() {
				if (invuneravel) {
					tempInvuneravel--;

					if (tempInvuneravel <= 0) {
						invuneravel = false;
						tempInvuneravel = 0;
						body.setFillColor(sf::Color::White);
					}
				}
			}

			void Jogador::receberDano() {
				if (!invuneravel) {
					num_vidas--;

					invuneravel = true;
					tempInvuneravel = 30;

					body.setFillColor(sf::Color::Yellow);
				}
			}

			int Jogador::getNumVidas() const {
				return num_vidas;
			}

			bool Jogador::estarVivo() const {
				return num_vidas > 0;
			}

		}
	}
}