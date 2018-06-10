//
// Created by paulo on 6/10/18.
//

#ifndef BUBBLES_BOLHASCONTROLLER_H
#define BUBBLES_BOLHASCONTROLLER_H

#include <vector>
#include "BolhaGui.h"
#include "AcaoBolha.h"

namespace bolhas { namespace model {
    class BolhaGui;
    class BolhasController {
        std::vector<model::BolhaGui> bolhas;
        std::vector<ALLEGRO_BITMAP *> explodindo, secando, normal;
        int x0, x1, y0, y1;
        DificuldadeJogo dificuldade;

        int geraX();
        int geraY();
        void carregaBitmaps();
        ALLEGRO_BITMAP *loadBitmap(const std::string &nome);

    public:
        BolhasController(DificuldadeJogo dificuldade =
                DificuldadeJogo::NORMAL);
        virtual ~BolhasController();

        ALLEGRO_BITMAP *getBitmap(model::AcaoBolha acao, int sprite) const;
        void adiciona();
    };
}}

#endif //BUBBLES_BOLHASCONTROLLER_H
