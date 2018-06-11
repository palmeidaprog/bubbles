//
// Created by paulo on 6/9/18.
//

#include "ZoomIn.h"

bolhas::animation::ZoomIn::ZoomIn(model::Fonts *font, model::Colors
        corOriginal, model::Colors cor, int max, int tamanho) :
        font(font), min(tamanho), max(max), crescimentoFonte(1),
        tamanho(tamanho) {
    this->cor = std::unique_ptr<model::Color> (new model::Color(cor));
    this->corOriginal = std::unique_ptr<model::Color> (new model::Color(
        corOriginal));
    intervalo = std::unique_ptr<model::Delay> (new model::Delay((double)
        1 / 100));
    percentual = static_cast<float>(100) * crescimentoFonte / min;
}

bolhas::animation::ZoomIn::~ZoomIn() {
}

void bolhas::animation::ZoomIn::parar() {
    font->setTamanho(tamanho);
    crescimentoFonte = 1;
    min = tamanho;
    percentual = static_cast<float>(100) * crescimentoFonte / min;
}

bool bolhas::animation::ZoomIn::animacao() {
    if(intervalo->ready()) {
        while (static_cast<float>(100) * (crescimentoFonte + 1) /
               min <= percentual) {
            ++crescimentoFonte;
        }

        min += crescimentoFonte;
        if (min >= max) {
            return false;
        }
        font->setTamanho(min);
        font->changeFont();
    }
    return true;
}

const bolhas::model::Color &bolhas::animation::ZoomIn::getCor() const {
    return ((max - ((max - tamanho) * 0.4)) > min) ? *corOriginal : *cor;
}

int bolhas::animation::ZoomIn::getMax() const {
    return max;
}

void bolhas::animation::ZoomIn::setMax(int max) {
    ZoomIn::max = max;
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
