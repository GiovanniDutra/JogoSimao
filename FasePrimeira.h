#pragma once

#ifndef FASEPRIMEIRA_H_
#define FASEPRIMEIRA_H_

#include "Fase.h"

namespace TrabalhoJogo {
	namespace Fases {
		class FasePrimeira : public Fase {
		private:
			const int maxLoboGelo;
			const int maxPlataformasGelidas;
		public:
			FasePrimeira();
			~FasePrimeira();

		protected:
			virtual void criarInimigos();
			virtual void criarObstaculos();
			void carregaFundo(const std::string& caminho);

			void criarLoboGelo(); //Criar Inimigo Medio
			void criarPlataformasGelidas();
		};
	}
}

#endif

