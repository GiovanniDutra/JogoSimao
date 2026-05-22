#include "Ente.h"
#include "GerenciadorGrafico.h"
#include <stdlib.h>
//#include "Figura.h"

namespace TrabalhoJogo {

	Gerenciadores::GerenciadorGrafico* Ente::pGG = NULL;

	Ente::Ente() : id(0), pFig(0) {}
	Ente::~Ente() {}

	void Ente::desenhar() {
		if (pGG != NULL) {
			pGG->desenharEnte(this);
		}
	}

	void Ente::setGG(Gerenciadores::GerenciadorGrafico* pGerenciadorGrafico) {
		pGG = pGerenciadorGrafico;
	}

	Figura* Ente::getFigura() const {
		return pFig;
	}

	void Ente::setFigura(Figura* pF) {
		pFig = pF;
	}
}
