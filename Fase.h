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

			int limiteChao;

			const int maxPinguins;
			const int maxPlataformas;

		public:
			Fase();
			~Fase();

			virtual void executar();
			virtual bool jogadorVivo() const = 0;
			bool acabou() const;

		protected:
			void criarPinguins();
			void criarPlataformas();
			void criarCenario();

			int inimigosVivos;
			bool faseConcluida;
			virtual void criarInimigos() = 0;
			virtual void criarObstaculos() = 0;

			int gerarQuantidadeAleatoria(const int maximo) const;
		};
	}
}

#endif