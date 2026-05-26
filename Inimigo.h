#pragma once
#include "Personagem.h"

namespace TrabalhoJogo {
    namespace Entidades {
        namespace Personagens {

            class Inimigo:public Personagem
            {
            protected:
                int dano;
                sf::RectangleShape boby;

            public:
                Inimigo();
                virtual ~Inimigo();

                virtual void executar();
                virtual void atacar(Personagem* pJogador);
            };
        }
    }
}

