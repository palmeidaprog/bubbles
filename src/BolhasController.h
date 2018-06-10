//
// Created by paulo on 6/10/18.
//

#ifndef BUBBLES_BOLHASCONTROLLER_H
#define BUBBLES_BOLHASCONTROLLER_H

#include <vector>
#include "BolhaGui.h"

namespace bolhas { namespace model {
    class BolhasController {
        std::vector<model::BolhaGui> bolhas;
        std::vector<ALLEGRO_BITMAP *> secando, enchendo, normal;
        int x0, x1, y0, y1;
        DificuldadeJogo dificuldade;

        int geraX();
        int geraY();

    public:
        BolhasController(DificuldadeJogo dificuldade);
        void adiciona();
    };
}}

#endif //BUBBLES_BOLHASCONTROLLER_H
