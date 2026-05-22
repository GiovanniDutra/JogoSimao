#include "Jogador.h"
#include "Inimigo.h"

#include "SFML/Graphics.hpp"

namespace TrabalhoJogo {
	namespace Entidades {
		namespace Personagens {

			Jogador::Jogador():
				Personagem(),
				pontos(0)
			{
				
			}

			Jogador::~Jogador()
			{

			}

			void Jogador::executar()
			{
				mover();
			}

			void Jogador::mover()
			{
				const int velocidade = 5;

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					x -= velocidade;
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					x += velocidade;
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					y -= velocidade;
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					y += velocidade;
				}
			}

			void Jogador::salvar()
			{

			}

			void Jogador::colidir(Inimigo* pInim)
			{
				if (pInim != NULL)
				{
					num_vidas--;
				}
			}

			void Jogador::addPontos(int valor)
			{
				pontos += valor;
			}

			int Jogador::getPontos() const
			{
				return pontos;
			}
		}
	}
}