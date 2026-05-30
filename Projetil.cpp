#include "Projetil.h"

namespace TrabalhoJogo {
	namespace Entidades {

		Projetil::Projetil(sf::Vector2f posicao, sf::Vector2f dire) : 
		Entidade(),
		velo(10.f),
		dano(3),
		ativo(true),
		direcao(dire)
		{
			body.setSize(sf::Vector2f(18.f, 8.f));
			body.setFillColor(sf::Color::Yellow);
			body.setPosition(posicao); //Não garanto que esteja certo
		}

		Projetil::~Projetil(){}

		void Projetil::executar()
		{
			if (!ativo)
			{
				return;
			}
			mover();
			//desenhar();
		}
		void Projetil::mover()
		{
			body.move(direcao * velo);

			//Caso saia da Janela
			if (body.getPosition().x > 2000 || body.getPosition().x < -50)
			{
				desativar();
			}
		}
		void Projetil::desativar()
		{
			ativo = false;
		}
		void Projetil::salvar() //Falta Implementar
		{
		
		}
		void Projetil::salvarDataBuffer() //Falta Implementar
		{

		}
		int Projetil::getDano() const 
		{
			return dano;
		}
	}
}