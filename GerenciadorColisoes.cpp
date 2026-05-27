#include "GerenciadorColisoes.h"

#include "Entidade.h"
#include "Jogador.h"
#include "Obstaculo.h"
#include "Projetil.h"
#include "Inimigo.h"

namespace TrabalhoJogo {
	namespace Gerenciadores {
		GerenciadorColisoes::GerenciadorColisoes() : pJog1(NULL) {}
		GerenciadorColisoes::~GerenciadorColisoes() {
			LIs.clear();
			LOs.clear();
			LPs.clear();
			pJog1 = NULL;
		}

		void GerenciadorColisoes::setJogador(Entidades::Personagens::Jogador* pJogador) {
			pJog1 = pJogador;
		}

		bool const GerenciadorColisoes::verificarColisao(Entidades::Entidade* pE1, Entidades::Entidade* pE2) const {
			if (pE1 == NULL || pE2 == NULL) {
				return false;
			}

			return pE1->getBody().getGlobalBounds().intersects(pE2->getBody().getGlobalBounds());
		}

		void GerenciadorColisoes::incluirInimigo(Entidades::Personagens::Inimigo* pI) {
			if (pI != NULL) {
				LIs.push_back(pI);
			}
		}

		void GerenciadorColisoes::incluirObstaculo(Entidades::Obstaculos::Obstaculo* pO) {
			if (pO != NULL) {
				LOs.push_back(pO);
			}
		}

		void GerenciadorColisoes::incluirProjetil(Entidades::Projetil* pP) {
			if (pP != NULL) {
				LPs.insert(pP);
			}
		}

		void GerenciadorColisoes::tratarColisoesJogsObstaculos() {
			if (pJog1 == NULL) {
				return;
			}

			std::list<Entidades::Obstaculos::Obstaculo*>::iterator it;

			for(it = LOs.begin(); it != LOs.end(); ++it) {
				if(*it != NULL) {
					(*it)->obstaculizar(pJog1);
				}
				// Talvez Colocar um Else com Erase
			}
		}

		void GerenciadorColisoes::tratarColisoesJogsInimigos() {
			if(pJog1 == NULL) {
				return;
			}

			for (int i = 0; i < LIs.size(); i++) {
				if(LIs[i] != NULL) {
					if (verificarColisao(pJog1, LIs[i])) {
						LIs[i]->danificar(pJog1);
					}
				}
			}
		}

		void GerenciadorColisoes::tratarColisoesJogsProjeteis() {
			//Implementar Quando Projetil Existir
		}

		void GerenciadorColisoes::executar() {
			tratarColisoesJogsObstaculos();
			tratarColisoesJogsInimigos();
			tratarColisoesJogsProjeteis();
		}
	}
}
