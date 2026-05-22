#include "Ente.h"
#include "GerenciadorGrafico.h"
#include <stdlib.h>

#include "SFML/Graphics.hpp"
//#include "Figura.h"

namespace TrabalhoJogo {

	Gerenciadores::GerenciadorGrafico* Ente::pGG = NULL;

	Ente::Ente() : id(0) {}
	Ente::~Ente() {}

	void Ente::desenhar() {
		if (pGG != NULL) {
			pGG->desenharEnte(this);
		}
	}

	void Ente::setGG(Gerenciadores::GerenciadorGrafico* pGerenciadorGrafico) {
		pGG = pGerenciadorGrafico;
	}
	bool Ente::carregarTextura(const char* caminho) {
		if (!textura.loadFromFile(caminho)) {
			return false;
		}
		
		sprite.setTexture(textura);

		return true;
	}

	sf::Sprite& Ente::getSprite() {
		return sprite;
	}

	const sf::Sprite& Ente::getSprite() const {
		return sprite;
	}
}
