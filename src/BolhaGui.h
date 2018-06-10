//
// Created by paulo on 6/10/18.
//

#ifndef BUBBLES_BOLHAGUI_H
#define BUBBLES_BOLHAGUI_H


#include <allegro5/bitmap.h>
#include "Bolha.h"
#include "BolhasController.h"
#include "AcaoBolha.h"

namespace bolhas { namespace model {
    class BolhasController;
    class BolhaGui {
        std::unique_ptr<model::Bolha> data;
        std::shared_ptr<BolhasController> controller;
        int posX, posY, tamanho = 1, spriteNum = 1;
        AcaoBolha acao;

    public:
        BolhaGui(const std::shared_ptr<BolhasController> &controller,
                 int posX, int posY);

        void renderizar(int x, int y);
    };
}}


#endif //BUBBLES_BOLHAGUI_H
