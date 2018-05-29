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

#include "MainView.h"
#include "Fonts.h"
#include "Delay.h"
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

namespace bolhas { namespace gui {
    class MainView;
    class MenuView {
        MainView &parent;
        model::Fonts *fonte, *title;
        const int ALTURA;
        const int LARGURA;
        model::Delay delay;
        int mult;

    public:
        MenuView(MainView &parent, const int altura, const int largura);
        virtual ~MenuView();

        void mostraMenu();
    };
}}

#endif // MENUVIEW_H