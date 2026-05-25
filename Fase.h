#pragma once

#ifndef FASE_H_
#define FASE_H_

#include "Ente.h"
#include "ListaEntidades.h"
#include "GerenciadorColisoes.h"


namespace TrabalhoJogo {
	namespace Fases {

		class Fase : public Ente
		{
		protected:
			ListaEntidades lista_ents;
			GerenciadorColisoes Gc;
			virtual void criaInimigos() = 0;
			virtual void criaObstaculos() = 0;

			virtual void criaPlataformas();
			virtual void criaCenario();

		public:
			Fase();
			virtual ~Fase();
			virtual void executar();
			virtual void salvar();
		};
	}
}
#endif

