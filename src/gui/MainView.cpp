/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */

// main View

#include "MainView.h"

using namespace bolhas;

namespace bolhas { namespace gui {
    MainView::MainView() : LARGURA(0), ALTURA(0) {
    }

    MainView::MainView(int largura, int altura) : LARGURA(largura), 
            ALTURA(altura) {
        janela = al_create_display(LARGURA, ALTURA);
        if(janela == NULL) {
            throw excecoes::JanelaException("Erro ao abrir janela principal.");
        }
    }

    MainView::~MainView() {
        al_destroy_display(janela); // fecha janela
    }
}}
