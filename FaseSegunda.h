#pragma once

#ifndef FASESEGUNDA_H_
#define FASESEGUNDA_H_

#include "Fase.h"

namespace TrabalhoJogo {
	namespace Fases {

		class FaseSegunda : public Fase {
		private:
			const int maxChefoes;
			const int maxEspinhoGelo;
		public:
			FaseSegunda();
			~FaseSegunda();
		protected:	
			void criarInimigos();
			void criarObstaculos();

			void criarEspinhoGelo();
			void criarGolemGelo();
			void carregaFundo(const std::string& caminho);

		};
	}
}

#endif