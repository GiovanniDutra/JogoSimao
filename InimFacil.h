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
				int direcao; // -1 para esquerda, 1 para direita
				
			public:
				InimFacil();
				virtual ~InimFacil();

				void executar();
				void danificar(Jogador* p);
				void salvar();
				void mover();


			};
		}
	}
}
#endif

