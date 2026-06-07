#include "GerenciadorGrafico.h"
#include "Ente.h"

#include "SFML/Graphics.hpp"

namespace TrabalhoJogo {
	namespace Gerenciadores {
		GerenciadorGrafico::GerenciadorGrafico() :
			obj(sf::VideoMode(1900, 1050), "TrabalhoJogo++")
		{
			obj.setFramerateLimit(60);
		}

		GerenciadorGrafico::~GerenciadorGrafico() {
			if (obj.isOpen()) {
				obj.close();
			}
		}

		bool GerenciadorGrafico::janelaAberta() const {
			return obj.isOpen();
		}

		void GerenciadorGrafico::fecharJanela() {
			obj.close();
		}

		sf::RenderWindow& GerenciadorGrafico::getJanela() {
			return obj;
		}

		void GerenciadorGrafico::tratarEventos() {
			sf::Event evento;

			while (obj.pollEvent(evento)) {
				if (evento.type == sf::Event::Closed) {
					obj.close();
				}
			}
		}

		void GerenciadorGrafico::limpar() {
			obj.clear(sf::Color(30, 30, 30));
		}

		void GerenciadorGrafico::mostrar() {
			obj.display();
		}

		void GerenciadorGrafico::desenharEnte(Ente* pE) {
			if (pE != NULL) {
				obj.draw(pE->getBody());
			}
		}
<<<<<<< HEAD

=======
>>>>>>> 241329947601a0d9eef8df0610e2b59093c258e6
		void GerenciadorGrafico::desenharFundo(sf::Drawable& drawable)
		{
			obj.draw(drawable);
		}
<<<<<<< HEAD

		sf::RenderWindow& GerenciadorGrafico::getJanela() {
			return obj;
		}
=======
>>>>>>> 241329947601a0d9eef8df0610e2b59093c258e6
	}
}
