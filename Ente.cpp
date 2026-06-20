#include "Ente.h"
#include "GerenciadorGrafico.h"
#include <stdlib.h>

#include "SFML/Graphics.hpp"

namespace TrabalhoJogo {

	Gerenciadores::GerenciadorGrafico* Ente::pGG = NULL;

	Ente::Ente() : id(0),
		body(sf::Vector2f(100.f, 100.f)){}
	
	Ente::~Ente() {}

	void Ente::desenhar() {
		if (pGG != NULL) {
			pGG->desenharEnte(this);
		}
	}

	void Ente::setGG(Gerenciadores::GerenciadorGrafico* pGerenciadorGrafico) {
		pGG = pGerenciadorGrafico;
	}
	sf::RectangleShape& Ente::getBody()
	{
		return body;
	}
	const sf::RectangleShape& Ente::getBody() const
	{
		return body;
	}

	bool Ente::carregarTextura(const char* caminho) {
		if (!texturaEntidade.loadFromFile(caminho)) {
			return false;
		}

		body.setTexture(&texturaEntidade);

		return true;
	}
}
