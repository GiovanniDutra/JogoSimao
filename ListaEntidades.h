#pragma once

#ifndef LISTAENTIDADES_H_
#define LISTAENTIDADES_H_

#include <list>

namespace TrabalhoJogo {
	namespace Entidades {
		class Entidade;
	}

	namespace Listas {
		class ListaEntidades {
		private:
			std::list<Entidades::Entidade*> LEs;
		public:
			ListaEntidades();
			~ListaEntidades();

			void incluirEntidade(Entidades::Entidade* pE);

			void percorrer();
			void desenhar();
			void limpar();

			void removerMortos();
		};
	}
}

#endif

