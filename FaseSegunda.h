#pragma once

#include "Fase.h"

namespace TrabalhoJogo {
	namespace Fases {

		class FaseSegunda : public Fase {
		public:
			FaseSegunda();
			~FaseSegunda();

		private:
			void criarInimigos() override;
			void criarObstaculos() override;

			void criarEspinhoGelo();
			void criarGolemGelo();
			void carregaFundo(const std::string& caminho);

		};
	}
}