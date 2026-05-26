#include "Personagem.h"

namespace TrabalhoJogo {
	namespace Entidades {
		namespace Personagens {
			Personagem::Personagem() :
				Entidade(),
				num_vidas(1) {}

			Personagem::~Personagem() {}

			void Personagem::salvaDataBuffer(){} //Falta Implementar

			void Personagem::receberDano(int dano)
			{
				num_vidas -= dano;
				if (num_vidas < 0)
				{
					num_vidas = 0;
				}
			}
		}
	}
}
