#pragma once

#ifndef GERENCIADOR_COLISOES_H
#define GERENCIADOR_COLISOES_H

#include <vector>
#include <list>
#include <set>

namespace TrabalhoJogo {
	namespace Entidades {
		class Entidade;
		class Projetil;

		namespace Personagens {
			class Jogador;
			class Inimigo;
		}
		namespace Obstaculos {
			class Obstaculo;
		}
	}

	namespace Gerenciadores {
		class GerenciadorColisoes {
		private:
			std::vector<Entidades::Personagens::Inimigo*> LIs;
			std::list<Entidades::Obstaculos::Obstaculo*> LOs;
			std::set<Entidades::Projetil*> LPs;

			Entidades::Personagens::Jogador* pJog1;
		private:
			bool const verificarColisao(Entidades::Entidade* pE1, Entidades::Entidade* pE2) const;

			void tratarColisoesJogoObstaculos();
			void tratarColisoesJogoInimigos();
			void tratarColisoesJogoProjeteis();
		public:
			GerenciadorColisoes();
			~GerenciadorColisoes();

			void setJogador(Entidades::Personagens::Jogador* pJogador);
			
			void incluirInimigo(Entidades::Personagens::Inimigo* pI);
			void incluirObstaculo(Entidades::Obstaculos::Obstaculo* pO);
			void incluirProjetil(Entidades::Projetil* pP);

			void executar();
		};
	}
}

#endif

