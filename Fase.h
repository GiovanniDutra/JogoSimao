#pragma once

#ifndef FASE_H_
#define FASE_H_

#include "Ente.h"
#include "ListaEntidades.h"
#include "GerenciadorColisoes.h"

namespace TrabalhoJogo {
	namespace Gerenciadores {
		class GerenciadorColisoes;
		class GerenciadorGrafico;
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

			sf::Texture texturaFundo;
			sf::Sprite fundo;

			bool terminarFase;
			bool vitoria;
		public:
			Fase();
			~Fase();
			
			virtual void executar();
			
			bool getTerminou() const;
			bool getVitoria() const;
		protected:
			void criarInimFaceis();
			void criarPlataformas();
			void criarCenario();
			void carregaFundo(const std::string& caminho);

			virtual void criarInimigos() = 0;
			virtual void criarObstaculos() = 0;
			
			void verificarFimFase();
		};
	}
}

#endif

