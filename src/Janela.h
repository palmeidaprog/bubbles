/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */

#ifndef BUBBLES_JANELA_H
#define BUBBLES_JANELA_H

#include "allegro5/allegro.h"

namespace bolhas { namespace gui {
    class Janela {
        int LARGURA;
        int ALTURA;
        ALLEGRO_DISPLAY *janela;

    public:
        Janela(int LARGURA, int ALTURA);
        virtual ~Janela();

    public:
        const int getAltura() const {
            return ALTURA;
        }

        const int getLargura() const {
            return LARGURA;
        }

        const ALLEGRO_DISPLAY *getJanela() const {
            return janela;
        }
    };
}}


#endif //BUBBLES_JANELA_H
