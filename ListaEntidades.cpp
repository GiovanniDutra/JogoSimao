#include "ListaEntidades.h"
#include "Entidade.h"
#include "Personagem.h"
#include "Inimigo.h"

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
		int ListaEntidades::contarInimigosVivos() const {

			int vivos = 0;
			int tamanho = LEs.getTamanho();

			for (int i = 0; i < tamanho; i++) {

				Entidades::Entidade* ent = LEs[i];
				if (!ent) continue;

				auto inimigo =
					dynamic_cast<TrabalhoJogo::Entidades::Personagens::Inimigo*>(ent);

				if (inimigo && inimigo->estarVivo()) {
					vivos++;
				}
			}

			return vivos;
		}
	}
}
