#include "Projetil.h"

namespace TrabalhoJogo {
	namespace Entidades {

		Projetil::Projetil() :
			Entidade(),
			ativo(false),
			velocidade(10.0f),
			dano(3),
			direcao(1.0f, 0.0f)
		{
			body.setSize(sf::Vector2f(18.0f, 8.0f));
			body.setFillColor(sf::Color::Yellow);
			
			body.setPosition(0, 0);
		}

		Projetil::Projetil(sf::Vector2f posicao, sf::Vector2f sentido) :
			Entidade(),
			ativo(true),
			velocidade(),
			dano(3),
			direcao(sentido)
		{
			body.setSize(sf::Vector2f(18.0f, 8.0f));
			body.setFillColor(sf::Color::Yellow);

			setPosicao((int)posicao.x, (int)posicao.y);
		}

		Projetil::~Projetil() {}

		void Projetil::prepararDisparo(sf::Vector2f posicao, sf::Vector2f sentido) {
			ativo = true;
			Entidade::ativar();

			direcao = sentido;

			zerarVelocidadeY();
			
			setPosicao((int)posicao.x, (int)posicao.y);
		}

		void Projetil::executar() {
			if (!ativo || !estaAtivo()) {
				return;
			}

			mover();
			aplicarGravidade();

			if (getX() < -50 || getX() > 1950 || getY() > 1100)
			{
				desativar();
			}
		}

		void Projetil::mover() {
			setPosicao(
				getX() + (int)(direcao.x * velocidade),
				getY()
			);
		}

		void Projetil::desativar() {
			ativo = false;
			Entidade::desativar();
		}

		int Projetil::getDano() const {
			return dano;
		}

		void Projetil::salvar() {} //Falta Implementar
	}
}