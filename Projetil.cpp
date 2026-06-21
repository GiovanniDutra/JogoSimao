#include "Projetil.h"
#include "GolemGelo.h"

namespace TrabalhoJogo {
	namespace Entidades {

		Projetil::Projetil() :
			Entidade(),
			ativo(false),
			velocidade(10.0f),
			dano(3),
			direcao(1.0f, 0.0f),
			pDono(NULL),
			empuxo(0.75f)
		{
			body.setSize(sf::Vector2f(35.0f, 20.0f));
			body.setFillColor(sf::Color::Yellow);

			if (!carregarTextura("assets/bolaneve.png"))
			{
				body.setFillColor(sf::Color::Red);
			}
			
			body.setPosition(0, 0);

			Entidade::desativar();
		}

		Projetil::Projetil(sf::Vector2f posicao, sf::Vector2f sentido) :
			Entidade(),
			ativo(true),
			velocidade(10.0f),
			dano(3),
			direcao(sentido),
			pDono(NULL),
			empuxo(0.85f)
		{
			body.setSize(sf::Vector2f(35.0f, 20.0f));
			body.setFillColor(sf::Color::Yellow);

			if (!carregarTextura("assets/bolaneve.png"))
			{
				body.setFillColor(sf::Color::Red);
			}

			setPosicao((int)posicao.x, (int)posicao.y);

		}

		Projetil::~Projetil() {
			pDono = NULL;
		}

		void Projetil::prepararDisparo(sf::Vector2f posicao, sf::Vector2f sentido) {
			ativo = true;
			Entidade::ativar();

			direcao = sentido;

			zerarVelocidadeY();
			
			setPosicao((int)posicao.x, (int)posicao.y);
		}

		void Projetil::executar() {
			if (!ativo || !estaAtivo()) {
				return;
			}

			int yAntes = getY();

			mover();
			aplicarGravidade();

			int queda = getY() - yAntes;
			int correcaoEmpuxo = (int)(queda * empuxo);

			setPosicao(getX(), getY() - correcaoEmpuxo);

			if (getX() < -100 || getX() > 2000 || getY() > 1200)
			{
				desativar();
			}
		}

		void Projetil::mover() {
			if (!ativo) {
				return;
			}
			
			setPosicao(
				getX() + (int)(direcao.x * velocidade),
				getY()
			);
		}

		void Projetil::desativar() {
			ativo = false;
			Entidade::desativar();
		}

		int Projetil::getDano() const {
			return dano;
		}

		void Projetil::salvar() {} //Falta Implementar

		void Projetil::setDono(Personagens::GolemGelo* pGolem) {
			pDono = pGolem;
		}

		Personagens::GolemGelo* Projetil::getDono() const {
			return pDono;
		}
	}
}