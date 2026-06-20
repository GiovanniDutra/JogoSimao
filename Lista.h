#pragma once

#ifndef LISTA_H_
#define LISTA_H_

#include <iostream>

namespace TrabalhoJogo {
	namespace Listas {
		template <class TL>

		class Lista {
		private:
			template <class TE>

			class Elemento {
			private:
				Elemento<TE>* pProx;
				TE* pInfo;
			public:
				Elemento() : pProx(NULL), pInfo(NULL) {}

				~Elemento() {
					pProx = NULL;
					pInfo = NULL;
				}

				void incluir(TE* pI) {
					pInfo = pI;
				}

				void setProx(Elemento<TE>* pE) {
					pProx = pE;
				}

				Elemento<TE>* getProx() const {
					return pProx;
				}

				TE* getInfo() const {
					return pInfo;
				}
			};

		private:
			Elemento<TL>* pPrimeiro;
			Elemento<TL>* pUltimo;
			int tamanho;
		public:
			Lista() : pPrimeiro(NULL), pUltimo(NULL), tamanho(0) {}

			~Lista() {
				limpar();
			}

			void incluir(TL* pI) {
				if (pI == NULL) {
					return;
				}

				Elemento<TL>* pNovo = new Elemento<TL>();
				pNovo->incluir(pI);

				if (pPrimeiro == NULL) {
					pPrimeiro = pNovo;
					pUltimo = pNovo;
				}
				else {
					pUltimo->setProx(pNovo);
					pUltimo = pNovo;
				}

				tamanho++;
			}

			void limpar() {
				Elemento<TL>* pAtual = pPrimeiro;
				Elemento<TL>* pProx = NULL;

				while (pAtual != NULL) {
					pProx = pAtual->getProx();
					delete pAtual;
					pAtual = pProx;
				}

				pPrimeiro = NULL;
				pUltimo = NULL;
				tamanho = 0;
			}

			int getTamanho() {
				return tamanho;
			}

			TL* operator[](int indice) const {
				if (indice < 0 || indice >= tamanho) {
					return 0;
				}

				Elemento<TL>* pAtual = pPrimeiro;
				
				int i = 0;

				while (pAtual != NULL && i < indice) {
					pAtual = pAtual->getProx();
					i++;
				}

				if (pAtual == NULL) {
					return 0;
				}

				return pAtual->getInfo();
			}
		};
	}
}

#endif


