#pragma once

#ifndef LISTAPRIMEIRA_H_
#define LISTAPRIMEIRA_H_

#include "Fase.h"

namespace TrabalhoJogo {
	namespace Fases {
		class FasePrimeira : public Fase {
		private:
			const int maxInimMedios;
		public:
			FasePrimeira();
			~FasePrimeira();

		protected:
			virtual void criarInimigos();
			virtual void criarObstaculos();

			void criarInimMedios();
			void criarObstMedios();
		};
	}
}

#endif

