#pragma once

#ifndef ENTIDADE_H_
#define ENTIDADE_H_

#include "Ente.h"
#include <ostream>
using namespace std;

namespace TrabalhoJogo {
	namespace Entidades {
		class Entidade : public Ente {
		protected:
			int x;
			int y;

			int velocidadeY;
			bool noChao;

			bool ativo;

			//ostream buffer; Falta Entender
		public:
			Entidade();
			virtual ~Entidade();
		protected:
			void salvarDataBuffer();
		public:
			virtual void executar() = 0;
			virtual void salvar() = 0;

			void setPosicao(int x, int y);
			int getX() const;
			int getY() const;

			virtual void aplicarGravidade();

			int getVelocidadeY() const;
			void zerarVelocidadeY();

			void setNoChao(bool estado);

			void ativar();
			void desativar();
			bool estaAtivo() const;

			sf::RectangleShape& getBody();
			const sf::RectangleShape& getBody() const;

		};
	}
}

#endif

