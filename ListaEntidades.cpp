#include "ListaEntidades.h"
#include "Entidade.h"
#include "Personagem.h"

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

					Entidades::Personagens::Personagem* pPersonagem = 
						dynamic_cast<Entidades::Personagens::Personagem*>(*it);

					if (pPersonagem != NULL && !pPersonagem->estarVivo()) {
						(*it)->marcarRemocao();
					}
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

		void ListaEntidades::removerMortos() {
			std::list<Entidades::Entidade*>::iterator it;

			while (it != LEs.end()) {
				Entidades::Entidade* pEntidade = *it;

				if (pEntidade == NULL) {
					it = LEs.erase(it);
					continue;
				}

				if (pEntidade->estaMarcado()) {
					delete pEntidade;
					it = LEs.erase(it);
					continue;
				}

				it++;
			}
		}
	}
}
