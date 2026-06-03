#pragma once

#ifndef GERENCIADORGRAFICO_H_
#define GERENCIADORGRAFICO_H_

#include <SFML/Graphics.hpp>

namespace TrabalhoJogo {
	class Ente;
}
namespace TrabalhoJogo {
	namespace Gerenciadores {
		class GerenciadorGrafico {
		private:
			sf::RenderWindow obj;
		public:
			GerenciadorGrafico();
			~GerenciadorGrafico();

			bool janelaAberta() const;
			void fecharJanela();

			void tratarEventos();
			void limpar();
			void mostrar();

			void desenharFundo(sf::Drawable& drawable);
			void desenharEnte(Ente* pE);
			sf::RenderWindow& getJanela();
		};
	}
}
#endif

