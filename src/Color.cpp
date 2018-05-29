/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */

#include "Color.h"

bolhas::model::Color::Color(Colors c) : c(c) {}

const ALLEGRO_COLOR &bolhas::model::Color::getPointer() const {
    return cor;
}

Colors bolhas::model::Color::getColor() const {
    return c;
}

void bolhas::model::Color::setColor(Colors c) {
    Color::c = c;

    switch(c) {
        case Colors::AZUL_ESCURO:
            cor = al_map_rgb(39, 9, 37);
            break;
        case Colors::PRETO:
            cor = al_map_rgb(255, 255, 255);
            break;
        case Colors::VERMELHO:
            cor = al_map_rgba_f(1, 0, 0, 1);
            break;
        default: // BRANCO
            cor = al_map_rgb(0, 0, 0);
            break;
    }
}
