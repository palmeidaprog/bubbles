/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */


#include "Passagem.h"

bool bolhas::animation::Passagem::animar() {
    if(reverse) {
        return animacaoReversa();
    } else {
        x -= speed;
        if (x <= 0) {
            al_set_clipping_rectangle(0, 0, largura, altura);
            x = y = 0;
            return false;
        }
        al_set_clipping_rectangle(x, 0, largura - x, altura);
        al_clear_to_color(cor->getCor());
        return true;
    }
}

bool bolhas::animation::Passagem::animacaoReversa() {
    x -= speed;
    if(x <= 0) {
        al_set_clipping_rectangle(0, 0, largura, altura);
        return false;
    }
    al_set_clipping_rectangle(0, 0, x, altura);
    al_clear_to_color(cor->getCor());
    return true;
}


bolhas::animation::Passagem::~Passagem() {

}

bolhas::animation::Passagem::Passagem(bolhas::model::Color *cor, int largura,
        int altura, bool reverse, int speed) : largura(largura),
        altura(altura), x(largura), y(0), reverse(reverse), speed(speed) {
    Passagem::cor = std::unique_ptr<model::Color>(cor);
}

