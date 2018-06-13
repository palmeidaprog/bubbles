/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */


#include "EntradaDados.h"

std::shared_ptr<bolhas::gui::EntradaDados> bolhas::gui::EntradaDados::instance;

bolhas::gui::EntradaDados::~EntradaDados() {
    al_destroy_bitmap(boneco);
    al_destroy_bitmap(balao);
}

bolhas::gui::EntradaDados::EntradaDados() : resp(""), posX(10), 
	posY(1000), balaoY(860), targetPosY(500), balaoX(75), 
	targetBalaoY(360), mostrando(false), enterPressionado(false) {
    boneco = al_load_bitmap("resources/images/a01.png");
    balao = al_load_bitmap("resources/images/b0.png");
    fonte = std::unique_ptr<model::Fonts>(new model::Fonts(
        "resources/fonts/Arial.ttf", 50));
    cor = std::unique_ptr<model::Color>(new model::Color(
        model::Colors::PRETO));
    instance = std::shared_ptr<bolhas::gui::EntradaDados>(this);
}

void bolhas::gui::EntradaDados::mostraBalao(bool mostrando) {
    this->mostrando = mostrando;
}


bool bolhas::gui::EntradaDados::isMostrando() const {
    return mostrando;
}

void bolhas::gui::EntradaDados::renderiza(int x, int y) {
    int pix = 18;
    if(mostrando) {
        if(posY - pix > targetPosY) {
            posY -= pix;
            balaoY -= pix;
        } else {
            posY = targetPosY;
            balaoY = targetBalaoY;
        }
    } else {
        if(posY + pix < 860) {
            posY += pix;
            balaoY += pix;
        } else {
            posY = 860;
            balaoY = 1000;
        }
    }
    al_draw_bitmap(boneco, posX, posY, 0);
    al_draw_bitmap(balao, balaoX, balaoY, 0);
    al_draw_text(fonte->getPointer(), cor->getCor(), balaoX + 65,
        balaoY + 35, ALLEGRO_ALIGN_LEFT, texto.c_str());
}

void bolhas::gui::EntradaDados::setTexto(const std::string &texto) {
    EntradaDados::texto = texto;
    this->texto += "=";
}

void bolhas::gui::EntradaDados::removeTexto() {
    if(texto[texto.size() - 1] != '=') {
        texto.pop_back();
        resp.pop_back();
    }
}

void bolhas::gui::EntradaDados::addTexto(char c) {
    texto += c;
    resp += c;
}

void bolhas::gui::EntradaDados::enter() {
    enterPressionado = true;
}

bool bolhas::gui::EntradaDados::isEnter() {
    if (enterPressionado) {
        enterPressionado = false;
        return true;
    }
    return false;
}

int bolhas::gui::EntradaDados::getResp() {
    int s = 0;

    try {
        s = std::stoi(resp);
    } catch(const std::invalid_argument &e) {
        // fazer nada
    }

    resp = "";
    while(texto[texto.size() - 1] != '=') {
        texto.pop_back();
    }
    return s;
}
