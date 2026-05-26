/*
#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
*/

#include "GerenciadorGrafico.h"
#include "GerenciadorColisoes.h"
#include "Ente.h"
#include "Jogador.h"
#include "Plataforma.h"

int main() {
    TrabalhoJogo::Gerenciadores::GerenciadorGrafico gerenciadorGrafico;
    TrabalhoJogo::Gerenciadores::GerenciadorColisoes gerenciadorColisoes;

    TrabalhoJogo::Ente::setGG(&gerenciadorGrafico);

    TrabalhoJogo::Entidades::Personagens::Jogador jogador;
    TrabalhoJogo::Entidades::Obstaculos::Plataforma plataforma;

    gerenciadorColisoes.setJogador(&jogador);
    gerenciadorColisoes.incluirObstaculo(&plataforma);

    while (gerenciadorGrafico.janelaAberta()) {
        gerenciadorGrafico.tratarEventos();
        gerenciadorGrafico.limpar();

        jogador.executar();
        
        gerenciadorColisoes.executar();

        plataforma.executar();
        jogador.desenhar();

        gerenciadorGrafico.mostrar();
    }
    return 0;
}
