/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */

#ifndef BUBBLES_PASSAGEM_H
#define BUBBLES_PASSAGEM_H

#include <memory>
#include "Transition.h"
#include "Color.h"
#include <allegro5/drawing.h>
#include <allegro5/bitmap.h>

namespace bolhas { namespace animation {
    class Passagem : public Transition {
        std::unique_ptr<model::Color> cor;
        int largura, altura, x, y, speed;
        bool reverse;

    public:
        Passagem(model::Color *cor, int largura, int altura,
                 bool reverse = false, int speed = 40);
        virtual ~Passagem();

        bool animar() override;
        bool animacaoReversa();
    };
}}


#endif //BUBBLES_PASSAGEM_H
