//
// Created by paulo on 6/10/18.
//

#include "BolhasController.h"

bolhas::model::BolhasController::BolhasController(
    bolhas::model::DificuldadeJogo dificuldade) {
    this->dificuldade = dificuldade;
}

void bolhas::model::BolhasController::adiciona() {
    bolhas.emplace_back(this, x, y);
}

int bolhas::model::BolhasController::geraX() {
    int diff = x1 - x0;
    return x0 + 40 + (rand() % diff - 80);
}

int bolhas::model::BolhasController::geraY() {
    int diff = y1 - y0;
    return y0 + 40 + (rand() % diff - 80);
}

