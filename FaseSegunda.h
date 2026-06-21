#pragma once

#ifndef FASESEGUNDA_H_
#define FASESEGUNDA_H_

#include "Fase.h"

#include <vector>

namespace TrabalhoJogo {
	namespace Entidades {
		class Projetil;

		namespace Personagens {
			class GolemGelo;
		}
	}
	
	namespace Fases {

		class FaseSegunda : public Fase {
		private:
			const int maxChefoes;
			const int maxEspinhoGelo;

			std::vector<Entidades::Personagens::GolemGelo*> chefes;
		public:
			FaseSegunda();
			~FaseSegunda();
			virtual bool jogadorVivo() const;

		protected:	
			void criarInimigos();
			void criarObstaculos();

			void criarEspinhoGelo();
			void criarGolemGelo();
			void criarProjeteis();

			void carregaFundo(const std::string& caminho);
		};
	}
}

#endif