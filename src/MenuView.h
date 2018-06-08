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
#include "MenuItem.h"
#include "Fonts.h"
#include "Delay.h"
#include "ZoomFont.h"
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <vector>

namespace bolhas { namespace gui {
    class MainView;
    class MenuView {
        MainView &parent;
        std::unique_ptr<model::Fonts> fonte, title;
        model::Fonts *marcada; // shared_ptr da crash com al_draw_text()
        std::unique_ptr<animation::ZoomFont> zoom;
        std::vector< std::unique_ptr<MenuItem> > itens;

        enum class Selecionado {
            NENHUM, JOGAR, OPCOES, SAIR
        };
        Selecionado selec;

        void criaMenu();
        MenuItem *adicionaEfeito(MenuItem *m);
        void criaMenuItem(int x, int y, const std::string &texto,
                          interfaces::Clickavel *click);

    public:
        MenuView(MainView &parent, int x, int y);
        virtual ~MenuView();

        void renderiza(int x, int y);
        void opcaoMenu(const std::string &texto, int pos,
                       Selecionado s);
        bool click(int x, int y);

    };
}}

#endif // MENUVIEW_H