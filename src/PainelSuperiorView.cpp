//
// Created by paulo on 6/10/18.
//

#include <MainView.h>
#include "PainelSuperiorView.h"

bolhas::gui::PainelSuperiorView::PainelSuperiorView(const bolhas::model::Fonts
        &fonte) {
    this->fonte = std::unique_ptr<model::Fonts>(new model::Fonts(fonte));
    cor = std::unique_ptr<model::Color> (new model::Color(
        model::Colors::PRETO));
}

bolhas::gui::PainelSuperiorView::~PainelSuperiorView() {

}

void bolhas::gui::PainelSuperiorView::renderizar(int x, int y) {
    using model::ScoreTime;
    char pontos[9];
    snprintf(pontos, 9, "%09d", ScoreTime::getInstance()->getScore());
    al_draw_text(fonte->getPointer(), cor->getCor(),
        MainView::getInstance()->getLargura() + 10, 5, ALLEGRO_ALIGN_RIGHT,
        pontos);
    al_draw_text(fonte->getPointer(), cor->getCor(),
        5, 5, ALLEGRO_ALIGN_LEFT,
        ScoreTime::getInstance()->mostraTime().c_str());
}

int bolhas::gui::PainelSuperiorView::getScore() const {
    return score;
}

void bolhas::gui::PainelSuperiorView::setScore(int score) {
    PainelSuperiorView::score = score;
}
