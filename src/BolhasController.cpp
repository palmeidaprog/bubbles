//
// Created by paulo on 6/10/18.
//

#include <allegro5/allegro.h>
#include "BolhasController.h"
#include "MainView.h"

bolhas::model::BolhasController::BolhasController(
    bolhas::model::DificuldadeJogo dificuldade) : x0(0), y0(40) {
    x1 = gui::MainView::getInstance()->getLargura();
    y1 = gui::MainView::getInstance()->getAltura();
    this->dificuldade = dificuldade;
    delay = std::unique_ptr<model::Delay> (new model::Delay(2));
    instance = std::shared_ptr<model::BolhasController> (this);
    fonte = std::unique_ptr<model::Fonts> (new model::Fonts(
        "../resources/fonts/agentred.ttf", 25));
    carregaBitmaps();
}

void bolhas::model::BolhasController::adiciona() {
    bolhas.emplace_back(new model::BolhaGui(instance.get(), geraX(),
        geraY()));
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
    /*destroiBitmaps(normal);
    destroiBitmaps(explodindo);
    destroiBitmaps(secando);*/
}

void bolhas::model::BolhasController::renderiza(int x, int y) {
    for(size_t i = 0; i < bolhas.size(); i++) {
        if(bolhas[i]->getAcao() == AcaoBolha::DESTRUIDA) {
            if(selected == bolhas[i].get()) {
                gui::EntradaDados::getInstance()->mostraBalao(false);
            }
            continue;
            /*bolhas[i].reset(nullptr);
            bolhas.erase(bolhas.begin() + i);
            --i;
            if(bolhas.empty()) {
                break;
            }*/
        } else {
            bolhas[i]->renderizar(x, y);
        }
    }
}

std::unique_ptr<bolhas::model::Fonts>
        &bolhas::model::BolhasController::getFonte() {
    return fonte;
}

bolhas::model::DificuldadeJogo
        bolhas::model::BolhasController::getDificuldade() const {
    return dificuldade;
}

bool bolhas::model::BolhasController::validaSpriteNum(AcaoBolha acao,
        int spriteNum) {
    if(acao == AcaoBolha::SECANDO && static_cast<size_t>(spriteNum) >=
            secando.size()) {
        return false;
    } else if(acao == AcaoBolha::EXPLODINDO && static_cast<size_t>(spriteNum)
            >= explodindo.size()) {
        return false;
    } else { // se nao for o caso de NORMAL e != 0 entao retorna true
        return !(acao == AcaoBolha::NORMAL && spriteNum);
    }
}

void bolhas::model::BolhasController::destroiBitmaps(
        std::vector<ALLEGRO_BITMAP *> v) {
    for(size_t i = 0; i < v.size(); i++) {
        al_destroy_bitmap(v[i]);
    }
}

double bolhas::model::BolhasController::tempoNascimento() {
    return 3 - (nivel - 1 * 0.1);
}

bool bolhas::model::BolhasController::click(int x, int y) {
    for(size_t i = 0; i < bolhas.size(); i++) {
        if(bolhas[i]->getAcao() != AcaoBolha::DESTRUIDA) {
            if(bolhas[i]->click(x, y)) {
                return true;
            }
        }
    }
    return false;
}

bolhas::model::BolhaGui *bolhas::model::BolhasController::getSelected() {
    return selected;
}

void bolhas::model::BolhasController::setSelected(bolhas::model::BolhaGui *selected) {
    BolhasController::selected = selected;
}

