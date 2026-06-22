#pragma once

#ifndef LISTAENTIDADES_H_
#define LISTAENTIDADES_H_

#include "Lista.h"

namespace TrabalhoJogo {
	namespace Entidades {
		class Entidade;
	}

	namespace Listas {
		class ListaEntidades {
		private:
			Lista<Entidades::Entidade> LEs;
		public:
			ListaEntidades();
			~ListaEntidades();

			void incluir(Entidades::Entidade* pE);

			void percorrer();
			void desenhar();
			void limpar();
			int contarInimigosVivos() const;
		};
	}
}

#endif

