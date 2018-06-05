//
// Created by Paulo Roberto Almeida Filho on 5/31/18.
//

#include "ZoomFont.h"

bolhas::animation::ZoomFont::ZoomFont(bolhas::model::Fonts *font) :
        font(font), mult(1), crescimentoFonte(5) {
    tamanho = font->getTamanho();
    max = (int) (font->getTamanho() * 1.2);
    min = (int) (font->getTamanho() * 0.8);
    intervalo = std::unique_ptr<model::Delay> (new model::Delay((double)
            1 / 30));
}

bolhas::animation::ZoomFont::~ZoomFont() {
    parar();
}

int bolhas::animation::ZoomFont::getMin() const {
    return min;
}

void bolhas::animation::ZoomFont::setMin(int min) {
    ZoomFont::min = min;
}

int bolhas::animation::ZoomFont::getMax() const {
    return max;
}

void bolhas::animation::ZoomFont::setMax(int max) {
    ZoomFont::max = max;
}

int bolhas::animation::ZoomFont::getCrescimentoFonte() const {
    return crescimentoFonte;
}

void bolhas::animation::ZoomFont::setCrescimentoFonte(int crescimentoFonte) {
    ZoomFont::crescimentoFonte = crescimentoFonte;
}


const bolhas::model::Fonts *bolhas::animation::ZoomFont::getFont() const {
    return font;
}

void bolhas::animation::ZoomFont::setFont(model::Fonts *f) {
    font = f;
}

void bolhas::animation::ZoomFont::animacao() {
    if(intervalo->ready()) {
        if(font->getTamanho() > max || font->getTamanho() < min) {
            mult *= -1;
        }
        font->setTamanho(font->getTamanho() + (crescimentoFonte * mult));
        font->changeFont();
    }
}

void bolhas::animation::ZoomFont::parar() {
    font->setTamanho(tamanho);
}


