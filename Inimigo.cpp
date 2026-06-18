#include "Inimigo.h"

namespace TrabalhoJogo {
	namespace Entidades {
		namespace Personagens {
			Inimigo::Inimigo() :
				Personagem(),
				nivelMaldade(1) {}

			Inimigo::~Inimigo() {}

			void Inimigo::salvarDataBuffer() {} //Implementar Depois

			void Inimigo::receberAtaque(int dano) {
				num_vidas -= dano;

				if (num_vidas <= 0) {
					num_vidas = 0;

					body.setSize(sf::Vector2f(0.f, 0.f));
					setPosicao(-100, -100);
				}
			}

			bool Inimigo::estarVivo() const {
				return num_vidas > 0;
			}
		}
	}
}
