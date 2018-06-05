//
// Created by Paulo Roberto Almeida Filho on 6/3/18.
//

#include "MenuItem.h"

bolhas::gui::MenuItem::MenuItem(const model::Fonts &fonte,
                                const model::Colors &cor,
                                const model::Colors &corSelecionada, float x,
                                float y, int flag, std::string texto)
                                : x(x), y(y), largura(0), altura(0),
                                flag(flag) {
    MenuItem::texto = std::move(texto);
    MenuItem::cor = std::unique_ptr<model::Color> (new model::Color(cor));
    MenuItem::corSelecionada = std::unique_ptr<model::Color>
            (new model::Color(corSelecionada));
    MenuItem::fonte = std::unique_ptr<model::Fonts> (new model::Fonts(fonte));
    const auto *f = new model::Fonts(MenuItem::fonte.get());
    largura = al_get_text_width(f->getPointer(), MenuItem::texto.c_str());
    altura = al_get_font_line_height(f->getPointer());
    delete f;
}

bolhas::gui::MenuItem::~MenuItem() {

}

void bolhas::gui::MenuItem::renderizar(int x, int y) {
    const model::Fonts *f = new model::Fonts(fonte.get());
    al_draw_text(f->getPointer(), ((ehSelecionado(x,y)) ?
            corSelecionada->getCor() : cor->getCor()), MenuItem::x,
                 MenuItem::y, flag, texto.c_str());
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

const std::unique_ptr<bolhas::model::Fonts> &bolhas::gui::MenuItem::getFonte()
        const {
    return fonte;
}

void bolhas::gui::MenuItem::setFonte(model::Fonts fonte) {
    //MenuItem::fonte = std::unique fonte) ;
}

// retorna se ponteiro esta sob
bool bolhas::gui::MenuItem::ehSelecionado(int x, int y) {
    float x0, x1, y1 = MenuItem::y, y0 = MenuItem::y - altura;
    if(flag == ALLEGRO_ALIGN_CENTER) {
        x0 = MenuItem::x - largura / 2;
        x1 = MenuItem::x + largura / 2;
    } else if(flag == ALLEGRO_ALIGN_LEFT) {
        x0 = MenuItem::x;
        x1 = MenuItem::x + largura;
    } else {
        x0 = MenuItem::x - largura;
        x1 = MenuItem::x;
    }
    return (x >= x0 && x <= x1 && y >= y0 && y <= y1);
}

const bolhas::model::Color & bolhas::gui::MenuItem::getCor() const {
    return *cor;
}

void bolhas::gui::MenuItem::setCor(std::unique_ptr<bolhas::model::Color>
        cor) {
    MenuItem::cor = std::move(cor);
}

const bolhas::model::Color &bolhas::gui::MenuItem::getCorSelecionada() const {
    return *corSelecionada;
}

void bolhas::gui::MenuItem::setCorSelectionada(
        std::unique_ptr<model::Color> corSelecionada) {
    MenuItem::corSelecionada = std::move(corSelecionada);
}

bolhas::gui::MenuItem::MenuItem(const bolhas::gui::MenuItem &m) :
        x(m.x), y(m.y), largura(m.largura), altura(m.altura), flag(m.flag) {
}
