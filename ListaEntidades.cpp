#include "ListaEntidades.h"
#include "Entidade.h"
#include "Personagem.h"

namespace TrabalhoJogo {
	namespace Listas {
		ListaEntidades::ListaEntidades(){}

		ListaEntidades::~ListaEntidades() {
			limpar();
		}

		void ListaEntidades::incluir(Entidades::Entidade* pE) {
			if (pE != NULL) {
				LEs += pE;
			}
		}

		void ListaEntidades::percorrer() {
			for (int i = 0; i < LEs.getTamanho(); i++) {
				Entidades::Entidade* pEntidade = LEs[i];

				if (pEntidade != NULL && pEntidade->estaAtivo()) {
					pEntidade->executar();	
				}
			}
		}

		void ListaEntidades::desenhar() {
			for (int i = 0; i < LEs.getTamanho(); i++) {
				Entidades::Entidade* pEntidade = LEs[i];

				if (pEntidade != NULL && pEntidade->estaAtivo()) {
					pEntidade->desenhar();
				}
			}
		}

		void ListaEntidades::limpar() {
			for (int i = 0; i < LEs.getTamanho(); i++) {
				Entidades::Entidade* pEntidade = LEs[i];

				if (pEntidade != NULL) {
					delete pEntidade;
					pEntidade = NULL;
				}
			}

			LEs.limpar();
		}
	}
}
