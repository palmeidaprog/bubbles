/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */

#include "MenuView.h"
#include "Colors.h"
#include "Color.h"
#include <memory>


// construtor

bolhas::gui::MenuView::MenuView(MainView &parent, int x, int y)
        : parent(parent),
          delay(model::Delay()), mult(1) {
    fonte = std::unique_ptr<model::Fonts>(new model::Fonts(parent.getFonte()));
    fonte->setTamanho(40);
    fonte->changeFont();
    marcada = new model::Fonts(fonte.get());
    title = std::unique_ptr<model::Fonts>(new
            model::Fonts("resources/fonts/BUBBS.TTF", 72));
    selec = Selecionado::NENHUM;
    renderiza(x, y);
}

void bolhas::gui::MenuView::renderiza(int x, int y) {
    int pos = 100;
    bool flag = false;
    model::Color azul(Colors::AZUL_ESCURO);
    model::Color vermelho(Colors::VERMELHO);



    al_draw_text(title->getPointer(), azul.getCor(),
                 parent.getLargura() / 2.0, pos, ALLEGRO_ALIGN_CENTRE,
                 "MENU");

    if(delay.test(2)) {
        if(title->getTamanho() > 100 || title->getTamanho() < 72) {
            mult *= -1;
        }
        title->setTamanho(title->getTamanho() + (5 * mult));
        title->changeFont();
    }

    pos += 180;
    opcaoMenu("Jogar", pos, Selecionado::JOGAR);
    pos += 100;
    opcaoMenu("Opcoes", pos, Selecionado::OPCOES);
    pos += 100;
    opcaoMenu("Sair", pos, Selecionado::SAIR);
}





bolhas::gui::MenuView::~MenuView() {


}

void bolhas::gui::MenuView::opcaoMenu(const std::string &texto,
                                      int pos, Selecionado s) {
    if(s == selec) {
        model::Color color(Colors::VERMELHO);
        al_draw_text(marcada->getPointer(), color.getCor(), (float)
                     parent.getLargura() / 2, pos, ALLEGRO_ALIGN_CENTER,
                     texto.c_str());
    } else {
        const model::Fonts *f = new model::Fonts(fonte.get());
        model::Color color(Colors::AZUL_ESCURO);
        al_draw_text(f->getPointer(), color.getCor(), (float)
                     parent.getLargura() / 2, pos, ALLEGRO_ALIGN_CENTER,
                     texto.c_str());
        delete f;
    }
}

void bolhas::gui::MenuView::criaMenu() {
    int y = 100;
    float x = (float) parent.getLargura() / 2;

    itens[0] = MenuItem(*title, x, y, ALLEGRO_ALIGN_CENTER, "MENU");
    y += 180;
    itens[1] = MenuItem(*fonte, x, y, ALLEGRO_ALIGN_CENTER, "Jogar");
    y += 100;
    itens[2] = MenuItem(*fonte, x, y, ALLEGRO_ALIGN_CENTER, "Tutorial");
    y += 100;
    itens[3] = MenuItem(*fonte, x, y, ALLEGRO_ALIGN_CENTER, "Opcoes");
    y += 100;
    itens[4] = MenuItem(*fonte, x, y, ALLEGRO_ALIGN_CENTER, "Sair");
}
