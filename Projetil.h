#pragma once

#ifndef PROJETIL_H_
#define PROJETIL_H_

#include "Entidade.h"

namespace TrabalhoJogo {
	namespace Entidades {

		class Projetil : public Entidade
		{
		protected:
			bool ativo;

			float velocidade;

			int dano;

			sf::Vector2f direcao;
		public:
			Projetil();
			Projetil(sf::Vector2f posicao, sf::Vector2f direcao);
			virtual ~Projetil();

			void executar();
			void salvar();

			void prepararDisparo(sf::Vector2f posicao, sf::Vector2f direcao);

			void mover();
			void desativar();
			
			int getDano() const;
		};
	}
}
#endif