#include "Entidade.h"
#include <iostream>

namespace TrabalhoJogo {
	namespace Entidades {
		Entidade::Entidade() :
			Ente(),
			x(0),
			y(0) {}

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
	}
}
