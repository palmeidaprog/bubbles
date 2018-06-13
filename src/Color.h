/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */

#ifndef BUBBLES_COLOR_H
#define BUBBLES_COLOR_H


#include <allegro5/color.h>
#include "Colors.h"

namespace bolhas { namespace model {
    class Color {
        Colors c;
        ALLEGRO_COLOR cor;

    public:
        Color(const Color &c);
        Color(Colors c);

        Colors getColor() const;
        void setColor(Colors c);

        const ALLEGRO_COLOR &getCor() const;
    };
}}


#endif //BUBBLES_COLOR_H
