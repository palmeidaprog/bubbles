/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */

#include "ZoomIn.h"

bolhas::animation::ZoomIn::ZoomIn(model::Fonts *font, model::Colors
        corOriginal, model::Colors cor, int valorMax, int tamanho) :
        font(font), valorMin(tamanho), valorMax(valorMax), crescimentoFonte(1),
        tamanho(tamanho) {
    this->cor = std::unique_ptr<model::Color> (new model::Color(cor));
    this->corOriginal = std::unique_ptr<model::Color> (new model::Color(
        corOriginal));
    intervalo = std::unique_ptr<model::Delay> (new model::Delay((double)
        1 / 100));
    percentual = static_cast<float>(100) * crescimentoFonte / valorMin;
}

bolhas::animation::ZoomIn::~ZoomIn() {
}

void bolhas::animation::ZoomIn::parar() {
    font->setTamanho(tamanho);
    crescimentoFonte = 1;
	valorMin = tamanho;
    percentual = static_cast<float>(100) * crescimentoFonte / valorMin;
}

bool bolhas::animation::ZoomIn::animacao() {
    if(intervalo->ready()) {
        while (static_cast<float>(100) * (crescimentoFonte + 1) /
			valorMin <= percentual) {
            ++crescimentoFonte;
        }

		valorMin += crescimentoFonte;
        if (valorMin >= valorMax) {
            return false;
        }
        font->setTamanho(valorMin);
        font->changeFont();
    }
    return true;
}

const bolhas::model::Color &bolhas::animation::ZoomIn::getCor() const {
    return ((valorMax - ((valorMax - tamanho) * 0.4)) > valorMin) ? *corOriginal : *cor;
}

int bolhas::animation::ZoomIn::getValorMax() const {
    return valorMax;
}

void bolhas::animation::ZoomIn::setValorMax(int valorMax) {
    ZoomIn::valorMax = valorMax;
}

int bolhas::animation::ZoomIn::getCrescimentoFonte() const {
    return crescimentoFonte;
}

void bolhas::animation::ZoomIn::setCrescimentoFonte(int crescimentoFonte) {
    ZoomIn::crescimentoFonte = crescimentoFonte;
}

double bolhas::animation::ZoomIn::getIntervalo() const {
    return intervalo->getDelay();
}

void bolhas::animation::ZoomIn::setIntervalo(double intervalo) {
    this->intervalo->setDelay(intervalo);
}
