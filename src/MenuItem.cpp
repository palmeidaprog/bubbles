//
// Created by Paulo Roberto Almeida Filho on 6/3/18.
//

#include "MenuItem.h"

bolhas::gui::MenuItem::MenuItem(const bolhas::model::Fonts &fonte,
                                const bolhas::model::Color &cor, float x,
                                float y, int flag, const std::string &texto)
                                : x(x), y(y), largura(0), altura(0),
                                flag(flag), texto(texto) {



}

bolhas::gui::MenuItem::~MenuItem() {

}

void bolhas::gui::MenuItem::renderizar() {
    const model::Fonts *f = new model::Fonts(fonte.get());
    al_draw_text(f->getPointer(), cor->getCor(), x, y, flag, texto.c_str());
    largura = al_get_text_width(f->getPointer(), texto.c_str());
    altura = al_get_text_width(f->getPointer(), texto.c_str());
    delete f;
}

float bolhas::gui::MenuItem::getX() const {
    return x;
}

void bolhas::gui::MenuItem::setX(float x) {
    MenuItem::x = x;
}

float bolhas::gui::MenuItem::getY() const {
    return y;
}

void bolhas::gui::MenuItem::setY(float y) {
    MenuItem::y = y;
}

float bolhas::gui::MenuItem::getLargura() const {
    return largura;
}

void bolhas::gui::MenuItem::setLargura(float largura) {
    MenuItem::largura = largura;
}

float bolhas::gui::MenuItem::getAltura() const {
    return altura;
}

void bolhas::gui::MenuItem::setAltura(float altura) {
    MenuItem::altura = altura;
}

int bolhas::gui::MenuItem::getFlag() const {
    return flag;
}

void bolhas::gui::MenuItem::setFlag(int flag) {
    MenuItem::flag = flag;
}

const std::string &bolhas::gui::MenuItem::getTexto() const {
    return texto;
}

void bolhas::gui::MenuItem::setTexto(const std::string &texto) {
    MenuItem::texto = texto;
}

const std::unique_ptr<bolhas::model::Color> &bolhas::gui::MenuItem::getCor()
        const {
    return cor;
}

void bolhas::gui::MenuItem::setCor(const std::unique_ptr<bolhas::model::Color>
        &cor) {
    MenuItem::cor = cor;
}

const std::unique_ptr<bolhas::model::Fonts> &bolhas::gui::MenuItem::getFonte()
        const {
    return fonte;
}

void bolhas::gui::MenuItem::setFonte(model::Fonts fonte) {
    MenuItem::fonte = std::unique fonte) ;
}

bool bolhas::gui::MenuItem::ehSelecionado(int x, int y) {
    return false;
}
