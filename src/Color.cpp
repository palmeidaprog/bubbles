/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */

#include "Color.h"

bolhas::model::Color::Color(model::Colors c) : c(c)  {
    setColor(c);
}

const ALLEGRO_COLOR &bolhas::model::Color::getCor() const {
    return cor;
}

bolhas::model::Colors bolhas::model::Color::getColor() const {
    return c;
}

void bolhas::model::Color::setColor(Colors c) {
    Color::c = c;
    using model::Colors;

    switch(c) {
        case Colors::AZUL_ESCURO:
            cor = al_map_rgb(39, 9, 37);
            break;
        case Colors::BRANCO:
            cor = al_map_rgb(255, 255, 255);
            break;
        case Colors::VERMELHO:
            cor = al_map_rgba_f(1, 0, 0, 1);
            break;
        case Colors::LARANJA_ACESO:
            cor = al_map_rgb(230, 133, 35);
            break;
        case Colors::BRANCO_FUMACA:
            cor = al_map_rgb(245, 245, 245);
            break;
        case Colors::AZUL_CLARO:
            cor = al_map_rgb(176, 196, 222);
            break;
        case Colors::AZUL_VIVO:
            cor = al_map_rgb(30, 144, 255);
            break;
        case Colors::CIANO:
            cor = al_map_rgb(0, 255, 255);
            break;
        case Colors::AZUL_PO:
            cor = al_map_rgb(176, 224, 230);
            break;
        default: // PRETO
            cor = al_map_rgb(0, 0, 0);
            break;
    }
}

bolhas::model::Color::Color(const bolhas::model::Color &c) {
    setColor(c.c);
}
