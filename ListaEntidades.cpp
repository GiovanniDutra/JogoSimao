#include "ListaEntidades.h"
#include "Entidade.h"

namespace TrabalhoJogo {
	namespace Listas {
		ListaEntidades::ListaEntidades(){}
		ListaEntidades::~ListaEntidades() {
			limpar();
		}

		void ListaEntidades::incluirEntidade(Entidades::Entidade* pE) {
			if (pE != NULL) {
				LEs.push_back(pE);
			}
		}

		void ListaEntidades::percorrer() {
			std::list<Entidades::Entidade*>::iterator it;

			for (it = LEs.begin(); it != LEs.end(); ++it) {
				if (*it != NULL) {
					(*it)->executar();

					(*it)->aplicarGravidade();
				}
			}
		}

		void ListaEntidades::desenhar() {
			std::list<Entidades::Entidade*>::iterator it;

			for (it = LEs.begin(); it != LEs.end(); ++it) {
				if (*it != NULL) {
					(*it)->desenhar();
				}
			}
		}

		void ListaEntidades::limpar() {
			std::list<Entidades::Entidade*>::iterator it;

			for (it = LEs.begin(); it != LEs.end(); ++it) {
				if (*it != NULL) {
					delete* it;
					*it = NULL;
				}
			}
			LEs.clear();
		}
	}
}
