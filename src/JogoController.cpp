/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */

#include "JogoController.h"

bolhas::gui::JogoController::~JogoController() {

}

bolhas::gui::JogoController::JogoController(bolhas::gui::JogoView
        *view) {
    this->view = std::shared_ptr<JogoView> (view);
    bolhas = std::unique_ptr<model::BolhasController>(new
            model::BolhasController());
}

int bolhas::gui::JogoController::getScore() const {
    return score;
}

void bolhas::gui::JogoController::setScore(int score) {
    JogoController::score = score;
}

int bolhas::gui::JogoController::getNivel() const {
    return nivel;
}

void bolhas::gui::JogoController::setNivel(int nivel) {
    JogoController::nivel = nivel;
}
