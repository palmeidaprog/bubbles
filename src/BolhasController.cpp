//
// Created by paulo on 6/10/18.
//

#include <allegro5/allegro.h>
#include "BolhasController.h"

bolhas::model::BolhasController::BolhasController(
    bolhas::model::DificuldadeJogo dificuldade) {
    this->dificuldade = dificuldade;
    carregaBitmaps();
}

void bolhas::model::BolhasController::adiciona() {
    std::shared_ptr<model::BolhasController> contr(this);
    bolhas.emplace_back(contr, geraX(), geraY());
}

int bolhas::model::BolhasController::geraX() {
    int diff = x1 - x0;
    return x0 + 40 + (rand() % diff - 80);
}

int bolhas::model::BolhasController::geraY() {
    int diff = y1 - y0;
    return y0 + 40 + (rand() % diff - 80);
}

ALLEGRO_BITMAP *bolhas::model::BolhasController::getBitmap(
        bolhas::model::AcaoBolha acao, int sprite) const {
    switch(acao) {
        case AcaoBolha::EXPLODINDO:
            return explodindo[sprite];
        case AcaoBolha::SECANDO:
            return secando[sprite];
        default: // NORMAL
            return normal[0];
    }
}

void bolhas::model::BolhasController::carregaBitmaps() {
    normal.emplace_back(loadBitmap(
        "../resources/sprites/bubble_right/bubble_pop_frame_01.png"));

    explodindo.emplace_back(loadBitmap(
        "../resources/sprites/bubble_right/bubble_pop_frame_01.png"));
    explodindo.emplace_back(loadBitmap(
        "../resources/sprites/bubble_right/bubble_pop_frame_02.png"));
    explodindo.emplace_back(loadBitmap(
        "../resources/sprites/bubble_right/bubble_pop_frame_03.png"));
    explodindo.emplace_back(loadBitmap(
        "../resources/sprites/bubble_right/bubble_pop_frame_04.png"));
    explodindo.emplace_back(loadBitmap(
        "../resources/sprites/bubble_right/bubble_pop_frame_05.png"));
    explodindo.emplace_back(loadBitmap(
        "../resources/sprites/bubble_right/bubble_pop_frame_06.png"));
    explodindo.emplace_back(loadBitmap(
        "../resources/sprites/bubble_right/bubble_pop_frame_07.png"));

    secando.emplace_back(loadBitmap(
        "../resources/sprites/bubble_wrong/bubble_pop_under_water_01.png"));
    secando.emplace_back(loadBitmap(
        "../resources/sprites/bubble_wrong/bubble_pop_under_water_02.png"));
    secando.emplace_back(loadBitmap(
        "../resources/sprites/bubble_wrong/bubble_pop_under_water_03.png"));
    secando.emplace_back(loadBitmap(
        "../resources/sprites/bubble_wrong/bubble_pop_under_water_04.png"));
    secando.emplace_back(loadBitmap(
        "../resources/sprites/bubble_wrong/bubble_pop_under_water_05.png"));
    secando.emplace_back(loadBitmap(
        "../resources/sprites/bubble_wrong/bubble_pop_under_water_06.png"));
    secando.emplace_back(loadBitmap(
        "../resources/sprites/bubble_wrong/bubble_pop_under_water_07.png"));
    secando.emplace_back(loadBitmap(
        "../resources/sprites/bubble_wrong/bubble_pop_under_water_08.png"));
}

ALLEGRO_BITMAP *bolhas::model::BolhasController::loadBitmap(const
        std::string &nome) {
    return al_load_bitmap(nome.c_str());
}

bolhas::model::BolhasController::~BolhasController() {

}

