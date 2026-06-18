#include "Inimigo.h"

namespace TrabalhoJogo {
    namespace Entidades {
        namespace Personagens {

            Inimigo::Inimigo() :
                Personagem(),
                nivelMaldade(1),
                hp(3),
                morto(false)
            {
                num_vidas = 1;
            }

            Inimigo::~Inimigo() {}

            void Inimigo::salvarDataBuffer() {}

            void Inimigo::receberDano(int dano)
            {
                if (morto) return;

                num_vidas -= dano;

                if (num_vidas <= 0)
                {
                    num_vidas = 0;
                    morto = true;
                }
            }

            bool Inimigo::estaMorto() const
            {
                return morto;
            }

        }
    }
}