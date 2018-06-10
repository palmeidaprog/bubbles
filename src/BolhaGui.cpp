//
// Created by paulo on 6/10/18.
//

#include <allegro5/allegro.h>
#include "BolhaGui.h"

void bolhas::model::BolhaGui::renderizar(int x, int y) {
    al_draw_bitmap(controller->getBitmap(acao, spriteNum), posX, posY, 0);
}

bolhas::model::BolhaGui::BolhaGui(const
        std::shared_ptr<bolhas::model::BolhasController> &controller,
        int posX, int posY) : controller(controller), posX(posX), posY(posY) {
}

bolhas::model::BolhaGui::~BolhaGui() {

}


