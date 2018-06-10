//
// Created by paulo on 6/10/18.
//

#include <allegro5/allegro.h>
#include "BolhaGui.h"

void bolhas::model::BolhaGui::renderizar(int x, int y) {
    al_draw_bitmap(controller->getBitmap(acao, spriteNum), posX, posY, 0);
}

bolhas::model::BolhaGui::BolhaGui(bolhas::model::BolhasController *controller,
        int posX, int posY) : posX(posX), posY(posY) {
    this->controller = std::shared_ptr<model::BolhasController> (controller);
}

bolhas::model::BolhaGui::~BolhaGui() {

}

/*bolhas::model::BolhaGui::BolhaGui(const bolhas::model::BolhaGui &bolha) :
        posX(std::bolha.posX), posY(bolha.posY),  data(bolha.data) {

}*/


