#pragma once
#include "Inimigo.h"

#ifndef INIMFACIL_H_
#define INIMFACIL_H_


namespace TrabalhoJogo {
	namespace Entidades {
		namespace Personagens {

			class Jogador;

			class InimFacil : public Inimigo
			{
			private:
				float raio;
				
			public:
				InimFacil();
				virtual ~InimFacil();

				void executar();
				void danificar(Jogador* p);

			};
		}
	}
}
#endif

