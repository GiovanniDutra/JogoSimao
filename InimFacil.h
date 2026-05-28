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
				int direcao;
				int limEsq;
				int limDir;
			public:
				InimFacil();
				InimFacil(int x, int y, int limEsq, int limDir); //Sobrecarga
				~InimFacil();

				void executar();
				void danificar(Jogador* p);
				void salvar();
				void mover();


			};
		}
	}
}
#endif

