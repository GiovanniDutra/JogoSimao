#include "Inimigo.h"

namespace TrabalhoJogo {
    namespace Entidades {
        namespace Personagens {

            Inimigo::Inimigo() :Personagem(), dano(5)
            {
                boby.setSize(sf::Vector2f(50.f, 50.f));
                boby.setFillColor(sf::Color::Red);

                body.setPosition(300, 300);
            }
            Inimigo::~Inimigo()
            {

            }
            void Inimigo::executar()
            {
                desenhar();
            }
            void Inimigo::atacar(Personagem* pJogador)
            {
                if (pJogador)
                {
                    pJogador->receberDano(dano);
                }
            }
        }
    }
}