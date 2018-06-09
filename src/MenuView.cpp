/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */

#include "MenuView.h"
#include "MudaEstado.h"
#include "Colors.h"
#include "Color.h"
#include <memory>


// construtor

bolhas::gui::MenuView::MenuView(MainView &parent, int x, int y)
        : parent(parent), select(nullptr) {
    fonte = std::unique_ptr<model::Fonts>(new model::Fonts(parent.getFonte()));
    fonte->setTamanho(40);
    fonte->changeFont();
    marcada = new model::Fonts(fonte.get());
    title = std::unique_ptr<model::Fonts>(new
            model::Fonts("../resources/fonts/bubbs.ttf", 56));
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
    al_destroy_sample(select);
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
    int y = 70; // 100
    float x = (float) parent.getLargura() / 2;
    using model::Colors;

    itens.emplace_back(new MenuItem(*title, Colors::LARANJA_ACESO,
                                    Colors::LARANJA_ACESO, x, y,
                                    ALLEGRO_ALIGN_CENTER, "Algebra"));
    y += 70;
    itens.emplace_back(new MenuItem(*title, Colors::LARANJA_ACESO,
                        Colors::LARANJA_ACESO, x, y,
                        ALLEGRO_ALIGN_CENTER, "Bolheana"));
    y += 130; // 180
    criaMenuItem(x, y, "Jogar", static_cast<interfaces::Clickavel *> (new
        interfaces::MudaEstado(Estado::JOGO)));

    /*itens.emplace_back(adicionaEfeito(new MenuItem(*fonte, Colors::AZUL_ESCURO,
                                    Colors::VERMELHO, x, y,
                                    ALLEGRO_ALIGN_CENTER, "Jogar")));*/
    y += 100;
    criaMenuItem(x, y, "Tutorial", static_cast<interfaces::Clickavel *> (new
        interfaces::MudaEstado(Estado::TUTORIAL)));
    /*itens.emplace_back(adicionaEfeito(new MenuItem(*fonte, Colors::AZUL_ESCURO,
                                    Colors::VERMELHO, x, y,
                                    ALLEGRO_ALIGN_CENTER, "Tutorial")));*/
    y += 100;
    criaMenuItem(x, y, "Opcoes", static_cast<interfaces::Clickavel *> (new
        interfaces::MudaEstado(Estado::OPCOES)));
    /*itens.emplace_back(adicionaEfeito(new MenuItem(*fonte, Colors::AZUL_ESCURO,
                                    Colors::VERMELHO, x, y,
                                    ALLEGRO_ALIGN_CENTER, "Opcoes")));*/
    y += 100;
    criaMenuItem(x, y, "Sair", static_cast<interfaces::Clickavel *> (new
        interfaces::MudaEstado(Estado::SAIR)));
    /*itens.emplace_back(adicionaEfeito(new MenuItem(*fonte, Colors::AZUL_ESCURO,
                                    Colors::VERMELHO, x, y,
                                    ALLEGRO_ALIGN_CENTER, "Sair")));*/
}

bolhas::gui::MenuItem *bolhas::gui::MenuView::adicionaEfeito(
        bolhas::gui::MenuItem *m) {
    using namespace animation;
    std::unique_ptr<EfeitoFonte> p = std::unique_ptr<EfeitoFonte>
            (dynamic_cast<EfeitoFonte*>(new ZoomFont(m->getFonte().get())));
    m->setEffect(p.release());
    return m;
}

void bolhas::gui::MenuView::criaMenuItem(int x, int y, const std::string &texto,
                                         bolhas::interfaces::Clickavel *click) {
    using model::Colors;
    MenuItem *m = new MenuItem(*fonte, Colors::AZUL_ESCURO,
                 Colors::VERMELHO, x, y,
                 ALLEGRO_ALIGN_CENTER, texto);
    itens.emplace_back(adicionaEfeito(m));
    m->setClick((click));
}

bool bolhas::gui::MenuView::click(int x, int y) {
    for(size_t i = 0; i < itens.size(); i++) {
        if(itens[i]->clickEvent(x, y)) {
            return true;
        }
    }
    return false;
}
