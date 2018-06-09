//
// Created by Paulo Roberto Almeida Filho on 6/8/18.
//

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
        int largura, altura, x, y;

    public:
        Passagem(model::Color *cor, int largura, int altura);

        virtual ~Passagem();

        bool animar() override;
    };
}}


#endif //BUBBLES_PASSAGEM_H
