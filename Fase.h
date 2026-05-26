#pragma once

#ifndef FASE_H_
#define FASE_H_

#include "Ente.h"
#include "ListaEntidades.h"
#include "GerenciadorColisoes.h"

namespace TrabalhoJogo {
	namespace Gerenciadores {
		class GerenciadorColisoes;
	}
	namespace Entidades {
		namespace Personagens {
			class Jogador;
		}
	}

	namespace Fases {
		class Fase : public Ente {
		protected:
			Listas::ListaEntidades listaEnts;
			Gerenciadores::GerenciadorColisoes* pGC;
			Entidades::Personagens::Jogador* pJog1;
		public:
			Fase();
			~Fase();
			virtual void executar();
		protected:
			void criarInimFaceis();
			void criarPlataformas();
			
			virtual void criarInimigos() = 0;
			virtual void criarObstaculos() = 0;
			
			virtual void criarCenario();
		};
	}
}

#endif

