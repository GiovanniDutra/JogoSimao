#include "Entidade.h"
#include <iostream>

namespace TrabalhoJogo {
	namespace Entidades {
		Entidade::Entidade() :
			Ente(),
			x(0),
			y(0),
			velocidadeY(0),
			noChao(false) {}

		Entidade::~Entidade() {}

		void Entidade::salvarDataBuffer() {} //Falta Implementar

		void Entidade::setPosicao(int x, int y) {
			this->x = x;
			this->y = y;

			body.setPosition(static_cast<float>(this->x), static_cast<float>(this->y));
		}

		int Entidade::getX() const {
			return x;
		}

		int Entidade::getY() const {
			return y;
		}

		int Entidade::getVelocidadeY() const {
			return velocidadeY;
		}

		void Entidade::zerarVelocidadeY() {
			velocidadeY = 0;
		}

		void Entidade::setNoChao(bool estado) {
			noChao = estado;
		}

		sf::RectangleShape& Entidade::getBody() {
			return body;
		}

		const sf::RectangleShape& Entidade::getBody() const {
			return body;
		}

		void Entidade::aplicarGravidade()
		{
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
	}
}
