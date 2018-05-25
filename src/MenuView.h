/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */


#ifndef MENUVIEW_H
#define MENUVIEW_H

#include "MenuView.h"
#include "Fonts.h"
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

namespace bolhas { namespace gui {
    class MainView;
    class MenuView {
        MainView &parent;
        model::Fonts *fonte;
        const int ALTURA;
        const int LARGURA;

    public:
        MenuView(MainView &parent_, const int altura, const int largura);
        virtual ~MenuView() { }

        void mostraMenu();
    };
}}

#endif // MENUVIEW_H