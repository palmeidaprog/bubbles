/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */

#include "MainView.h"
#include "PainelSuperiorView.h"

bolhas::gui::PainelSuperiorView::PainelSuperiorView(const bolhas::model::Fonts
        &fonte) : score(0) {
    this->fonte = std::unique_ptr<model::Fonts>(new model::Fonts(fonte));
    cor = std::unique_ptr<model::Color> (new model::Color(
        model::Colors::PRETO));
}

bolhas::gui::PainelSuperiorView::~PainelSuperiorView() {

}

void bolhas::gui::PainelSuperiorView::renderizar(int x, int y) {
    using model::ScoreTime;
    char pontos[9];
     #if defined(WIN32) || defined(_WIN32)
	_snprintf_s(pontos, 9, _TRUNCATE, "%09d", ScoreTime::getInstance()->getScore());
	#else
    snprintf(pontos, 9, "%09d", ScoreTime::getInstance()->getScore());
	#endif
    al_draw_text(fonte->getPointer(), cor->getCor(),
        MainView::getInstance()->getLargura() - 25, 5, ALLEGRO_ALIGN_RIGHT,
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
