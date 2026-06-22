#include "GolemGelo.h"
#include "Jogador.h"
#include "Projetil.h"

#include <cmath>

namespace TrabalhoJogo {
	namespace Entidades {
		namespace Personagens {
			GolemGelo::GolemGelo() :
				Inimigo(),
				socoGlacial(5),
				direcao(1),
				limEsq(0),
				limDir(0),
				jaAtirou(false),
				pProjetil(NULL),
				pAlvo(NULL),
				contadorMovimento(0)
			{
				nivelMaldade = 3;
				num_vidas = 10;

				body.setSize(sf::Vector2f(90.f, 100.f));
				body.setFillColor(sf::Color::Cyan);

				if (!carregarTextura("assets/GolemGelo.png")) {
					body.setFillColor(sf::Color::Red);
				}

				setPosicao(250, 300);
			}

			GolemGelo::GolemGelo(int x, int y, int lE, int lD) :
				Inimigo(),
				socoGlacial(5),
				direcao(1),
				limEsq(lE),
				limDir(lD),
				jaAtirou(false),
				pProjetil(NULL),
				pAlvo(NULL),
				contadorMovimento(0)
			{
				nivelMaldade = 3;
				num_vidas = 5;

				body.setSize(sf::Vector2f(90.f, 100.f));
				body.setFillColor(sf::Color::Cyan);

				if (!carregarTextura("assets/GolemGelo.png")) {
					body.setFillColor(sf::Color::Red);
				}

				setPosicao(x, y);

			}

			GolemGelo::~GolemGelo(){
				pProjetil = NULL;
				pAlvo = NULL;
			}

			void GolemGelo::mover() {
				const int tempoPreparacao = 40;
				const int tempoInvestida = 35;
				const int velocidadePreparacao = 1;
				const int velocidadeInvestida = 7;

				contadorMovimento++;

				if (contadorMovimento == 1 && pAlvo != NULL)
				{
					if (pAlvo->getX() < getX())
					{
						direcao = -1;
					}
					else
					{
						direcao = 1;
					}
				}

				int velocidadeAtual = velocidadePreparacao;

				if (contadorMovimento > tempoPreparacao)
				{
					velocidadeAtual = velocidadeInvestida;
				}

				int novoX = getX() + velocidadeAtual * direcao;

				if (novoX < limEsq)
				{
					novoX = limEsq;
					direcao = 1;
					contadorMovimento = 0;
				}
				else if (novoX > limDir)
				{
					novoX = limDir;
					direcao = -1;
					contadorMovimento = 0;
				}

				setPosicao(novoX, getY());

				if (contadorMovimento >= tempoPreparacao + tempoInvestida)
				{
					contadorMovimento = 0;
				}
			}

			void GolemGelo::executar()
			{
				mover();
				aplicarGravidade();

				if (!jaAtirou) {
					atirar();
				}
			}

			void GolemGelo::danificar(Jogador* pJogador)
			{
				if (pJogador == NULL) {
					return;
				}

				if (!estaAtivo()) {
					return;
				}

				int dano = socoGlacial * nivelMaldade;

				pJogador->receberDano(dano);
			}
			void GolemGelo::salvar()
			{
				// Implementar depois
			}

			void GolemGelo::setProjetil(Projetil* pP) {
				pProjetil = pP;

				if (pP != NULL) {
					pP->setDono(this);
				}
			}

			void GolemGelo::setAlvo(Jogador* pJogador) {
				pAlvo = pJogador;
			}

			void GolemGelo::atirar() {
				if (jaAtirou || pProjetil == NULL || pAlvo == NULL) {
					return;
				}

				sf::Vector2f posicao;
				posicao.x = (float)getX();
				posicao.y = (float)getY();

				float dx = (float)(pAlvo->getX() - getX());
				float dy = (float)(pAlvo->getY() - getY());

				float modulo = sqrt(dx * dx + dy * dy);

				sf::Vector2f direcao;

				if (modulo != 0.0f) {
					direcao.x = dx / modulo;
					direcao.y = dy / modulo;
				}
				else {
					direcao.x = 1.0f;
					direcao.y = 0.0f;
				}

				pProjetil->prepararDisparo(posicao, direcao);

				jaAtirou = true;
			}
		}
	}
}
