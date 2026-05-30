#pragma once

#ifndef PROJETIL_H_
#define PROJETIL_H_
#include "Entidade.h"

namespace TrabalhoJogo {
	namespace Entidades {

		class Projetil : Entidade
		{
		protected:
			float velo;
			int dano;
			bool ativo;
			sf::Vector2f direcao;

		public:

			Projetil(sf::Vector2f posicao, sf::Vector2f direcao);
			virtual ~Projetil();
			virtual void executar();
			virtual void salvar();

			void mover();
			void desativar();
			void salvarDataBuffer();
			int getDano() const;
		};
	}
}


#endif // !PROJETIL_H_
