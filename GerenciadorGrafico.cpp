#include "GerenciadorGrafico.h"
#include "Ente.h"

namespace TrabalhoJogo {
	namespace Gerenciadores {
		GerenciadorGrafico::GerenciadorGrafico() :
			obj(sf::VideoMode(1280, 720), "TrabalhoJogo++")
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

		void GerenciadorGrafico::desenharEnte(Ente* pE) {} //Falta Implementar

		void GerenciadorGrafico::desenharFigura(const sf::Drawable& figura) {
			obj.draw(figura);
		}
	}
}
