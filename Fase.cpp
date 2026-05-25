#include "Fase.h"

namespace TrabalhoJogo {
	namespace Fases {

		Fase::Fase() {}
		Fase::~Fase() {}

		void Fase::executar()
		{
			
		}
		void Fase::salvar()
		{
			//salva como a fase esta
		}
		void Fase::criaPlataformas()
		{

		}
		void Fase::criaCenario()
		{
			criaPlataformas();
			criaCenario();
		}

	}
}