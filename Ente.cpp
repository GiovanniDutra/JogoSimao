#include "Ente.h"
#include "GerenciadorGrafico.h"
#include <stdlib.h>

#include "SFML/Graphics.hpp"

#include <iostream>
#include <stdexcept>
#include <string>

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
		try {
			if (caminho == NULL) {
				throw std::runtime_error("Caminho da textura nulo.");
			}

			if (!texturaEntidade.loadFromFile(caminho)) {
				throw std::runtime_error(std::string("Erro ao carregar textura: ") + caminho);
			}

			body.setTexture(&texturaEntidade);

			return true;
		}
		catch (const std::exception& erro) {
			std::cout << erro.what() << std::endl;
			return false;
		}
	}
}
