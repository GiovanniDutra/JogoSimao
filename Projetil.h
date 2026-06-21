#pragma once

#ifndef PROJETIL_H_
#define PROJETIL_H_

#include "Entidade.h"

namespace TrabalhoJogo {
	namespace Entidades {
		namespace Personagens 
		{
			class GolemGelo;
		}

		class Projetil : public Entidade
		{
		protected:
			bool ativo;
			float velocidade;
			int dano;

			float velocidadeProjetil;
			float empuxo;

			sf::Vector2f direcao;

			Personagens::GolemGelo* pDono;
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

			void setDono(Personagens::GolemGelo* pGolem);
			Personagens::GolemGelo* getDono() const;
		};
	}
}
#endif