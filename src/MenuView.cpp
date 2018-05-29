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


// construtor
namespace bolhas { namespace gui {
    MenuView::MenuView(MainView &parent, const int
            altura, const int largura) : parent(parent), fonte(NULL),
            title(nullptr), ALTURA(altura), LARGURA(largura),
            delay(model::Delay()), mult(1) {
        fonte = new model::Fonts(parent.getFonte());
        title = new model::Fonts("resources/fonts/BUBBS.TTF", 72);
    }



    void MenuView::mostraMenu() {
        int pos = 100;
        model::Color azul(Colors::AZUL_ESCURO);
        model::Color vermelho(Colors::VERMELHO);

        al_draw_text(title->getPointer(), azul,
                     LARGURA / 2.0, pos, ALLEGRO_ALIGN_CENTRE, "MENU");
        if(delay.test(4)) {
            if(title->getTamanho() > 100 || title->getTamanho() < 72) {
                mult *= -1;
            }
            title->setTamanho(title->getTamanho() + (5 * mult));
            title->changeFont();
        }
        fonte->setTamanho(40);
        fonte->changeFont();
        pos += 180;
        al_draw_text(fonte->getPointer(), vermelho, (double)
                      LARGURA / 2, pos, ALLEGRO_ALIGN_CENTER, "Jogar");
        pos += 100;
        al_draw_text(fonte->getPointer(), azul, LARGURA
                      /2, pos, ALLEGRO_ALIGN_CENTER, "Opcoes");
        pos += 100;
        al_draw_text(fonte->getPointer(), azul, LARGURA
                        /2, pos, ALLEGRO_ALIGN_CENTER, "Sair");
        /*al_draw_textf(fonte->getPointer(), al_map_rgb(0, 0, 0), LARGURA / 2.0,
                      210, ALLEGRO_ALIGN_CENTRE, "Teste %d - %s", 3, "Uma str");*/
        /*al_draw_textf(fonte, al_map_rgb(0, 0, 0), LARGURA / 2, 250,
            ALLEGRO_ALIGN_CENTRE, "Teste %d - %s", 3, "Uma str");*/
    }

        MenuView::~MenuView() {
            delete fonte;
            delete title;
        }
    }}