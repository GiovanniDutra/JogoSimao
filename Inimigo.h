#pragma once

#ifndef INIMIGO_H_
#define INIMIGO_H_

#include "Personagem.h"

namespace TrabalhoJogo {
    namespace Entidades {
        namespace Personagens {

            class Jogador;

            class Inimigo : public Personagem {
            protected:
                int nivelMaldade;

                int hp;
                bool morto;

            public:
                Inimigo();
                virtual ~Inimigo();

                void salvarDataBuffer();

                virtual void executar() = 0;
                virtual void danificar(Jogador* p) = 0;
                virtual void salvar() = 0;

                void receberDano(int dano = 1);

                bool estaMorto() const;
            };

        }
    }
}

#endif