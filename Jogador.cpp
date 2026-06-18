#include "Jogador.h"
#include "Inimigo.h"

#include "SFML/Graphics.hpp"
#include <iostream>

namespace TrabalhoJogo {
	namespace Entidades {
		namespace Personagens {

			Jogador::Jogador():
				Personagem(),
				pontos(0),
				invuneravel(false),
				tempInvuneravel(0),
				atacando(false),
				tempoAtacando(0),
				duracaoAtaque(12),
				intervaloAtaqueCont(0),
				intervaloAtaque(18),
				forca(1),
				direcao(1)
			{
				num_vidas = 100;

				body.setSize(sf::Vector2f(40.f, 50.f));

				body.setFillColor(sf::Color::White);

				if (!carregarTextura("assets/jogador1.png")) {
					body.setFillColor(sf::Color::Red);
				}

				setPosicao(50, 300);
			}

			Jogador::~Jogador() {}

			void Jogador::executar()
			{
				mover();

				if (intervaloAtaqueCont > 0) {
					intervaloAtaqueCont--;
				}
				if (atacando) {
					if (tempoAtacando > 0) {
						tempoAtacando--;
					}
					if(tempoAtacando == 0) {
						atacando = false;
					}
				}

				atualizarInvunerabilidade();
			}

			void Jogador::salvar() {}

			void Jogador::mover()
			{
				const int velocidadeX = 5;

				int novoX = getX();
				int antigoX = getX();

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				{
					novoX -= velocidadeX;
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				{
					novoX += velocidadeX;
				}

				if (novoX < antigoX) {
					direcao = -1;
				}
				else if(novoX > antigoX) {
					direcao = 1;
				}

				if(sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
					atacar();
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				{
					pular();
				}

				setPosicao(novoX, getY());
			}

			void Jogador::colidir(Inimigo* pInim)
			{
				if (pInim != NULL)
				{
					//marca colisao;
				}
			}

			void Jogador::pular() {
				if (noChao)
				{
					velocidadeY = -25;
					noChao = false;
				}
			}

			void Jogador::addPontos(int valor) {
				pontos += valor;
			}

			int Jogador::getPontos() const {
				return pontos;
			}

			void Jogador::atualizarInvunerabilidade() {
				if(!invuneravel) {
					return;
				}

				if(tempInvuneravel > 0) {
					tempInvuneravel--;

					if(tempInvuneravel == 0) {
						invuneravel = false;
						body.setFillColor(sf::Color::White);
					}
				}
			}

			void Jogador::receberDano(int dano) {
				if (invuneravel || dano <= 0) {
					return;
				}

				num_vidas -= dano;
				
				if (num_vidas < 0) {
					num_vidas = 0;
				}

				invuneravel = true;
				tempInvuneravel = 60;

				body.setFillColor(sf::Color::Yellow);
			}

			int Jogador::getNumVidas() const {
				return num_vidas;
			}

			bool Jogador::estarVivo() const {
				return num_vidas > 0;
			}

			void Jogador::atacar() {
				if(intervaloAtaqueCont > 0 || atacando) {
					return;
				}

				atacando = true;
				tempoAtacando = duracaoAtaque;
				intervaloAtaqueCont = intervaloAtaque;

				std::cout << "[DEBUG] Jogador::atacar() acionado. Forca = " << forca << "Duracao = " << duracaoAtaque << " Intervalo = " << std::endl;
			}

			bool Jogador::estaAtacando() const {
				return atacando;
			}

			int Jogador::getForcaAtaque() const {
				return forca;
			}

			int Jogador::getDirecaoAtaque() const {
				return direcao;
			}
		}
	}
}