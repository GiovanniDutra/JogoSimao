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
		};
	}
}

#endif

