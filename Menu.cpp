#include "Menu.h"
#include "GerenciadorGrafico.h"
#include <iostream>
#include "Jogo.h"
namespace TrabalhoJogo{
    Menu::Menu() :
        opcaoEscoli(-1),
        faseEscolhida(-1),
        numJogadores(1),
        estado(EstadoMenu::PRINCIPAL),
        pos(0)
    {
        window = new sf::RenderWindow();
        font = new sf::Font();
        image = new sf::Texture();
        bg = new sf::Sprite();

        set_values();
        montarMenuPrincipal();
    }

    Menu::~Menu() {
        delete window;
        delete font;
        delete image;
        delete bg;
    }

    void Menu::set_values() {
        window->create(
            sf::VideoMode(1280, 720),
            "Menu",
            sf::Style::Titlebar | sf::Style::Close
        );

        font->loadFromFile("assets/ethn.otf");
        image->loadFromFile("assets/menu.png");

        bg->setTexture(*image);

        sf::Vector2u texSize = image->getSize();
        sf::Vector2u winSize = window->getSize();

        bg->setScale(
            static_cast<float>(winSize.x) / texSize.x,
            static_cast<float>(winSize.y) / texSize.y
        );
    }

    void Menu::loop_events() {
        sf::Event event;

        while (window->pollEvent(event)) {

            if (event.type == sf::Event::Closed)
                window->close();

            if (event.type == sf::Event::KeyPressed) {

                if (event.key.code == sf::Keyboard::Down) {
                    texts[pos].setOutlineThickness(0);
                    pos = (pos + 1) % texts.size();
                    texts[pos].setOutlineThickness(4);
                }

                if (event.key.code == sf::Keyboard::Up) {
                    texts[pos].setOutlineThickness(0);
                    pos = (pos == 0 ? texts.size() - 1 : pos - 1);
                    texts[pos].setOutlineThickness(4);
                }

                if (event.key.code == sf::Keyboard::Enter) {

                    if (estado == EstadoMenu::PRINCIPAL) {
                        if (pos == 0) {
                            estado = EstadoMenu::SELECAO_FASE;
                            montarMenuFases();
                        }
                        else {
                            window->close();
                        }
                    }

                    else if (estado == EstadoMenu::SELECAO_FASE) {

                        if (pos == texts.size() - 1) {
                            estado = EstadoMenu::PRINCIPAL;
                            montarMenuPrincipal();
                        }
                        else {
                            faseEscolhida = pos + 1;
                            estado = EstadoMenu::SELECAO_JOGADORES;
                            montarMenuJogadores();
                        }
                    }

                    else if (estado == EstadoMenu::SELECAO_JOGADORES) {

                        if (pos == texts.size() - 1) { 
                            estado = EstadoMenu::SELECAO_FASE;
                            montarMenuFases();
                        }
                        else {
                            numJogadores = (pos == 0 ? 1 : 2);
                            opcaoEscoli = 1;
                            window->close();
                        }
                    }
                }
            }
        }
    }

    void Menu::desenharPausa(sf::RenderWindow& window) {

        sf::RectangleShape overlay;
        overlay.setSize(sf::Vector2f(window.getSize()));
        overlay.setFillColor(sf::Color(0, 0, 0, 160));
        window.draw(overlay);

        static sf::Font font;
        static bool loaded = false;

        if (!loaded) {
            font.loadFromFile("assets/ethn.otf");
            loaded = true;
        }

        sf::Text texto;
        texto.setFont(font);
        texto.setString("PAUSADO\n\nESC para voltar");
        texto.setCharacterSize(50);
        texto.setFillColor(sf::Color::White);

        sf::FloatRect bounds = texto.getLocalBounds();
        texto.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
        texto.setPosition(
            window.getSize().x / 2.f,
            window.getSize().y / 2.f
        );

        window.draw(texto);
    }

    void Menu::executarGameOver() {
        sf::RenderWindow& janela = pGG->getJanela();

        while (janela.isOpen()) {
            sf::Event event;
            while (janela.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    janela.close();

                if (event.type == sf::Event::KeyPressed &&
                    event.key.code == sf::Keyboard::Enter)
                    return;
            }

            janela.clear(sf::Color::Black);
            // desenhar "GAME OVER"
            janela.display();
        }
    }

    void Menu::draw_all() {
        window->clear();
        window->draw(*bg);

        for (std::vector<sf::Text>::iterator it = texts.begin(); it != texts.end(); ++it)
            window->draw(*it);

        window->display();
    }

    void Menu::executar() {
        while (window->isOpen()) {
            loop_events();
            draw_all();
        }
    }


    void Menu::centralizarTexto(sf::Text& texto, float y) {
        sf::FloatRect bounds = texto.getLocalBounds();
        texto.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
        texto.setPosition(window->getSize().x / 2.f, y);
    }


    void Menu::montarMenuPrincipal() {

        trocarFundo("assets/menu.png");

        options = { "Play", "Quit" };
        texts.clear();
        texts.resize(options.size());

        float yInicial = 350.f;

        for (size_t i = 0; i < options.size(); i++) {
            texts[i].setFont(*font);
            texts[i].setString(options[i]);
            texts[i].setCharacterSize(36);
            texts[i].setOutlineColor(sf::Color::Black);
            centralizarTexto(texts[i], yInicial + i * 110);
        }

        pos = 0;
        texts[0].setOutlineThickness(4);
    }

    void Menu::montarMenuFases() {

        trocarFundo("assets/menu2.png");

        options = { "Fase 1", "Fase 2", "Voltar" };
        texts.clear();
        texts.resize(options.size());

        for (size_t i = 0; i < options.size(); i++) {
            texts[i].setFont(*font);
            texts[i].setString(options[i]);
            texts[i].setCharacterSize(32);
            texts[i].setPosition(560, 305 + i * 90);
            texts[i].setOutlineColor(sf::Color::Black);
        }

        pos = 0;
        texts[0].setOutlineThickness(4);
    }

    void Menu::montarMenuJogadores() {

        trocarFundo("assets/menu3.png");

        options = { "1 Jogador", "2 Jogadores" };
        texts.clear();
        texts.resize(options.size());

        for (size_t i = 0; i < options.size(); i++) {
            texts[i].setFont(*font);
            texts[i].setString(options[i]);
            texts[i].setCharacterSize(32);
            texts[i].setPosition(490, 370 + i * 110);
            texts[i].setOutlineColor(sf::Color::Black);
        }

        pos = 0;
        texts[0].setOutlineThickness(4);
    }

    void Menu::trocarFundo(const std::string& caminho) {

        if (!image->loadFromFile(caminho)) {
            std::cout << "Erro ao carregar fundo: " << caminho << std::endl;
            return;
        }

        bg->setTexture(*image, true);

        sf::Vector2u texSize = image->getSize();
        sf::Vector2u winSize = window->getSize();

        bg->setScale(
            static_cast<float>(winSize.x) / texSize.x,
            static_cast<float>(winSize.y) / texSize.y
        );

    }

    bool Menu::deveIniciarJogo() const {
        return opcaoEscoli == 1;
    }

    int Menu::getFaseEscolhida() const {
        return faseEscolhida;
    }

    int Menu::getNumJogadores() const {
        return numJogadores;
    }
}