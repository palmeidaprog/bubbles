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
        *view) : score(0), nivel(1) {
    this->view = std::shared_ptr<JogoView> (view);
    bolhas = std::unique_ptr<model::BolhasController>(new
            model::BolhasController());
    delay = std::unique_ptr<model::Delay> (new model::Delay(
        bolhas->tempoNascimento()));
    dificuldade = model::DificuldadeJogo::NORMAL;
    segundos = std::unique_ptr<model::Delay> (new model::Delay(1));
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

void bolhas::gui::JogoController::adicionaBolha() {
    bolhas->adiciona();
}

void bolhas::gui::JogoController::renderizaBolhas(int x, int y) {
    if(segundos->ready()) {
        model::ScoreTime::getInstance()->removeTime(1);
    }
    if(delay->ready()) {
        adicionaBolha();
    }
    bolhas->renderiza(x, y);
}

bool bolhas::gui::JogoController::click(int x, int y) {
    return bolhas->click(x, y);
}

bolhas::model::BolhasController *bolhas::gui::JogoController::getBolhas() {
    return bolhas.get();
}
