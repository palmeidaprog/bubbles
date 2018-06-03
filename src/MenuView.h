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
#include "ZoomFont.h"
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

namespace bolhas { namespace gui {
    class MainView;
    class MenuView {
        MainView &parent;
        model::Delay delay;
        int mult;
        std::unique_ptr<model::Fonts> fonte, title;
        model::Fonts *marcada; // shared_ptr da crash com al_draw_text()
        std::unique_ptr<animation::ZoomFont> zoom;

        enum class Selecionado {
            NENHUM, JOGAR, OPCOES, SAIR
        };
        Selecionado selec;

    public:
        MenuView(MainView &parent);
        virtual ~MenuView();

        void mostraMenu();
        void opcaoMenu(const std::string &texto, int pos,
                       Selecionado s);
    };
}}

#endif // MENUVIEW_H