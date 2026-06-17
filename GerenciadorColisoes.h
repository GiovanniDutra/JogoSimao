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

			int limiteChao;
		private:
			bool const verificarColisao(Entidades::Entidade* pE1, Entidades::Entidade* pE2) const;

			void tratarColisaoChao(Entidades::Entidade* pEntidade);
			void tratarColisaoEntidadeObstaculo(Entidades::Entidade* pEntidade, Entidades::Obstaculos::Obstaculo* pObstaculo);

			void tratarColisoesJogsObstaculos();
			void tratarColisoesJogsInimigos();
			void tratarColisoesJogsProjeteis();
		public:
			GerenciadorColisoes();
			~GerenciadorColisoes();

			void setJogador(Entidades::Personagens::Jogador* pJogador);

			void setLimiteChao(int limite);
			
			void incluirInimigo(Entidades::Personagens::Inimigo* pI);
			void incluirObstaculo(Entidades::Obstaculos::Obstaculo* pO);
			void incluirProjetil(Entidades::Projetil* pP);

			void executar();
		};
	}
}

#endif

