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

#include "GerenciadorGrafico.h"
#include "Ente.h"
#include "FasePrimeira.h"

int main() {
    TrabalhoJogo::Gerenciadores::GerenciadorGrafico gerenciadorGrafico;
    TrabalhoJogo::Gerenciadores::GerenciadorColisoes gerenciadorColisoes;

    TrabalhoJogo::Ente::setGG(&gerenciadorGrafico);
    
	TrabalhoJogo::Fases::FasePrimeira fasePrimeira;

    while (gerenciadorGrafico.janelaAberta()) {
        gerenciadorGrafico.tratarEventos();
        gerenciadorGrafico.limpar();

        fasePrimeira.executar();
        if (fasePrimeira.getTerminou()) {
            gerenciadorGrafico.fecharJanela();
        }
        
        //GerenciadorColisoes.executar();

        gerenciadorGrafico.mostrar();
    }
    return 0;
}
*/

#include "Jogo.h"

int main()
{
    TrabalhoJogo::Jogo jogo;
    jogo.executar();

    return 0;
}
