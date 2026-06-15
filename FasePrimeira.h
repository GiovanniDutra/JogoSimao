#pragma once

#ifndef FASEPRIMEIRA_H_
#define FASEPRIMEIRA_H_

#include "Fase.h"

namespace TrabalhoJogo {
	namespace Fases {
		class FasePrimeira : public Fase {
		private:
			const int maxLoboGelo; //Max Inimigos Medios
		public:
			FasePrimeira();
			~FasePrimeira();

		protected:
			virtual void criarInimigos();
			virtual void criarObstaculos();

			void criarLoboGelo(); //Criar Inimigo Medio
			void criarObstMedios();
		};
	}
}

#endif

