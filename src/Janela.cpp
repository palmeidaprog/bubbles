/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */

#include "Janela.h"
#include "JanelaException.h"

bolhas::gui::Janela::~Janela() {
    al_destroy_display(janela); // fecha janela
    janela = nullptr;
}

bolhas::gui::Janela::Janela(int LARGURA, int ALTURA) :
        LARGURA(LARGURA), ALTURA(ALTURA), janela(nullptr) {
        janela = al_create_display(LARGURA, ALTURA);
        if(janela == nullptr) {
            throw excecoes::JanelaException("Erro ao abrir janela principal."
            );
        }
}

const int bolhas::gui::Janela::getAltura() const {
    return ALTURA;
}

const int bolhas::gui::Janela::getLargura() const {
    return LARGURA;
}

ALLEGRO_DISPLAY *bolhas::gui::Janela::getJanela() const {
    return janela;
}
