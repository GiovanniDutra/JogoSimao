#pragma once

#ifndef ENTE_H_
#define ENTE_H_

#include "SFML/Graphics.hpp"

namespace TrabalhoJogo {
	
	class Figura;

	namespace Gerenciadores {
		class GerenciadorGrafico;
	}

	class Ente {
	protected:
		int id;
		static Gerenciadores::GerenciadorGrafico* pGG;
		sf::Texture texturaEntidade;
		sf::RectangleShape body;
	public:
		Ente();
		virtual ~Ente();

		virtual void executar() = 0;
		void desenhar();

		static void setGG(Gerenciadores::GerenciadorGrafico* pGG);

		//void setTexture()
	};
}

#endif

