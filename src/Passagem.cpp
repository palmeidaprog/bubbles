//
// Created by Paulo Roberto Almeida Filho on 6/8/18.
//


#include "Passagem.h"

bool bolhas::animation::Passagem::animar() {
    x -= 100;
    if(x <= 0) {
        return false;
    }
    al_set_clipping_rectangle(x, 0, largura - x, altura);
    al_clear_to_color(cor->getCor());
    return true;
}

bolhas::animation::Passagem::~Passagem() {

}

bolhas::animation::Passagem::Passagem(bolhas::model::Color *cor, int largura,
                                      int altura) : largura(largura),
                                                    altura(altura) {
    Passagem::cor = std::unique_ptr<model::Color>(cor);
}
