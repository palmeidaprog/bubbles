/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */

#include "MenuView.h"
#include "MainView.h"

// construtor
namespace bolhas { namespace gui {
    MenuView::MenuView(MainView &parent_, ALLEGRO_FONT *fonte_, const int 
            altura, const int largura) : parent(parent_), fonte(fonte_), 
            ALTURA(altura), LARGURA(largura) {
        mostraMenu();
    }

    void MenuView::mostraMenu() const {
    /*    al_draw_text(fonte, al_map_rgb(0, 0, 255), LARGURA / 2, 90,
            ALLEGRO_ALIGN_CENTRE, "Centro");
        al_draw_textf(fonte, al_map_rgb(0, 0, 0), LARGURA / 2, 250, 
            ALLEGRO_ALIGN_CENTRE, "Teste %d - %s", 3, "Uma str");*/
    }
}}