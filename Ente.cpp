#include "Ente.h"
#include "GerenciadorGrafico.h"
#include <stdlib.h>

#include "SFML/Graphics.hpp"
//#include "Figura.h"

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
}
