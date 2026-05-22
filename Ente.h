#pragma once

#ifndef ENTE_H_
#define ENTE_H_

namespace TrabalhoJogo {
	
	class Figura;

	namespace Gerenciadores {
		class GerenciadorGrafico;
	}

	class Ente {
	protected:
		int id;
		static Gerenciadores::GerenciadorGrafico* pGG;
		Figura* pFig;
	public:
		Ente();
		virtual ~Ente();

		virtual void executar() = 0;
		void desenhar();

		static void setGG(Gerenciadores::GerenciadorGrafico* pGG);

		Figura* getFigura() const;
		void setFigura(Figura* pF);
	};
}

#endif

