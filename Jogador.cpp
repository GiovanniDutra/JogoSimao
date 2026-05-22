#include "Jogador.h"
#include "Inimigo.h"

namespace TrabalhoJogo {
	namespace Entidades {
		namespace Personagens {

			Jogador::Jogador():
				pontos(0)
			{
				
			}
			Jogador::~Jogador()
			{

			}
			void Jogador::executar()
			{
				mover();
			}
			void Jogador::mover()
			{
				
			}
			void Jogador::salvar()
			{

			}
			void Jogador::colidir(Inimigo* inimigo)
			{
				if (inimigo)
				{
					
				}
			}
			void Jogador::addPontos(int valor)
			{
				pontos += valor;
			}
			int Jogador::getPontos() const
			{
				return pontos;
			}
		}
	}
}