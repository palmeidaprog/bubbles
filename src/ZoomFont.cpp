//
// Created by Paulo Roberto Almeida Filho on 5/31/18.
//

#include "ZoomFont.h"

bolhas::animation::ZoomFont::ZoomFont(bolhas::model::Fonts *font) : font(font) {}

bolhas::animation::ZoomFont::~ZoomFont() {

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

int bolhas::animation::ZoomFont::getFramesDelay() const {
    return framesDelay;
}

void bolhas::animation::ZoomFont::setFramesDelay(int framesDelay) {
    ZoomFont::framesDelay = framesDelay;
}

const bolhas::model::Fonts &bolhas::animation::ZoomFont::getFont() const {
    return *font;
}

void bolhas::animation::ZoomFont::setFont(const model::Fonts& f) {
    font.reset(new model::Fonts(f));
}


