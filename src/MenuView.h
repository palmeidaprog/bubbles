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

#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

namespace bolhas { namespace gui {
    class MainView;
    class MenuView {
        MainView &parent;
        ALLEGRO_FONT *fonte;
        const int ALTURA;
        const int LARGURA;

    public:
        MenuView(MainView &parent_, ALLEGRO_FONT *fonte_, const int altura, 
            const int largura);
        virtual ~MenuView() { }

        void mostraMenu() const;
    };
}}

#endif // MENUVIEW_H