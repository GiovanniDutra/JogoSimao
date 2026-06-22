#pragma once
#include "Jogo.h"
#include <SFML/Graphics.hpp>
#include <iostream>

namespace TrabalhoJogo{
    enum EstadoMenu {
        PRINCIPAL,
        SELECAO_FASE,
        SELECAO_JOGADORES,
        SAIR
    };
    class Menu {
    private:
        int pos;
        bool pressed, theselect;
        int opcaoEscoli;

        sf::RenderWindow* window;
        sf::RectangleShape* winclose;
        sf::Font* font;
        sf::Texture* image;
        sf::Sprite* bg;

        sf::Vector2i pos_mouse;
        sf::Vector2f mouse_coord;

        std::vector<const char*> options;
        std::vector<sf::Vector2f> coords;
        std::vector<sf::Text> texts;
        std::vector<std::size_t> sizes;
        Gerenciadores::GerenciadorGrafico* pGG;

        EstadoMenu estado;

        int faseEscolhida;
        int numJogadores;

        void montarMenuPrincipal();
        void montarMenuFases();
        void montarMenuJogadores();

    protected:
        void set_values();
        void loop_events();
        void draw_all();

    public:
        Menu();
        ~Menu();
        void executar();
        //void executarGameOver();
        void desenharTelaVitoria(sf::RenderWindow& window);
        void desenharPausa(sf::RenderWindow& window);
        bool deveIniciarJogo() const;
        bool pausado = false;
        int getFaseEscolhida() const;
        int getNumJogadores() const;
        void centralizarTexto(sf::Text& texto, float y);
        void trocarFundo(const std::string& caminho);
    };
}