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
        : parent(parent) {
    fonte = std::unique_ptr<model::Fonts>(new model::Fonts(parent.getFonte()));
    fonte->setTamanho(40);
    fonte->changeFont();
    marcada = new model::Fonts(fonte.get());
    title = std::unique_ptr<model::Fonts>(new
            model::Fonts("../resources/fonts/bubbs.ttf", 72));
    zoom = std::unique_ptr<animation::ZoomFont>
            (new animation::ZoomFont(fonte.get()));
    selec = Selecionado::NENHUM;
    criaMenu();
    renderiza(x, y);
}

void bolhas::gui::MenuView::renderiza(int x, int y) {
    for(size_t i = 0; i < itens.size(); i++) {
        itens[i]->renderizar(x, y);
    }
/*
    if(delaySegundos.test(2)) {
        if(title->getTamanho() > 100 || title->getTamanho() < 72) {
            mult *= -1;
        }
        title->setTamanho(title->getTamanho() + (5 * mult));
        title->changeFont();
    }
*/
}

bolhas::gui::MenuView::~MenuView() {


}

void bolhas::gui::MenuView::opcaoMenu(const std::string &texto,
                                      int pos, Selecionado s) {
    if(s == selec) {
        model::Color color(model::Colors::VERMELHO);
        al_draw_text(marcada->getPointer(), color.getCor(), (float)
                     parent.getLargura() / 2, pos, ALLEGRO_ALIGN_CENTER,
                     texto.c_str());
    } else {
        const model::Fonts *f = new model::Fonts(fonte.get());
        model::Color color(model::Colors::AZUL_ESCURO);
        al_draw_text(f->getPointer(), color.getCor(), (float)
                     parent.getLargura() / 2, pos, ALLEGRO_ALIGN_CENTER,
                     texto.c_str());
        delete f;
    }
}

void bolhas::gui::MenuView::criaMenu() {
    int y = 100;
    float x = (float) parent.getLargura() / 2;
    using model::Colors;

    itens.emplace_back(new MenuItem(*title, Colors::AZUL_ESCURO,
                                    Colors::AZUL_ESCURO, x, y,
                                    ALLEGRO_ALIGN_CENTER, "MENU"));
    y += 180;
    itens.emplace_back(new MenuItem(*fonte, Colors::AZUL_ESCURO,
                                    Colors::VERMELHO, x, y,
                                    ALLEGRO_ALIGN_CENTER, "Jogar"));
    y += 100;
    itens.emplace_back(new MenuItem(*fonte, Colors::AZUL_ESCURO,
                                    Colors::VERMELHO, x, y,
                                    ALLEGRO_ALIGN_CENTER, "Tutorial"));
    y += 100;
    itens.emplace_back(new MenuItem(*fonte, Colors::AZUL_ESCURO,
                                    Colors::VERMELHO, x, y,
                                    ALLEGRO_ALIGN_CENTER, "Opcoes"));
    y += 100;
    itens.emplace_back(new MenuItem(*fonte, Colors::AZUL_ESCURO,
                                    Colors::VERMELHO, x, y,
                                    ALLEGRO_ALIGN_CENTER, "Sair"));
}
