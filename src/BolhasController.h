//
// Created by paulo on 6/10/18.
//

#ifndef BUBBLES_BOLHASCONTROLLER_H
#define BUBBLES_BOLHASCONTROLLER_H

#include <vector>
#include "BolhaGui.h"
#include "AcaoBolha.h"
#include "Fonts.h"

namespace bolhas { namespace model {
    class BolhaGui;
    class BolhasController {
        std::shared_ptr<model::BolhasController> instance;
        std::unique_ptr<model::Fonts> fonte;
        std::vector<std::unique_ptr<model::BolhaGui>> bolhas;
        std::vector<ALLEGRO_BITMAP *> explodindo, secando, normal;
        std::unique_ptr<model::Delay> delay;
        model::BolhaGui *selected;
        int x0, x1, y0, y1, nivel;
        DificuldadeJogo dificuldade;

        int geraX();
        int geraY();
        void carregaBitmaps();
        void destroiBitmaps(std::vector<ALLEGRO_BITMAP *> v);
        ALLEGRO_BITMAP *loadBitmap(const std::string &nome);

    public:
        BolhasController(DificuldadeJogo dificuldade =
                DificuldadeJogo::NORMAL);
        virtual ~BolhasController();

        ALLEGRO_BITMAP *getBitmap(model::AcaoBolha acao, int sprite) const;
        void adiciona();
        void renderiza(int x, int y);
        std::unique_ptr<model::Fonts> &getFonte();
        DificuldadeJogo getDificuldade() const;
        bool validaSpriteNum(AcaoBolha acao, int spriteNum);
        double tempoNascimento();
        bool click(int x, int y);
        BolhaGui *getSelected();
        void setSelected(BolhaGui *selected);
    };
}}

#endif //BUBBLES_BOLHASCONTROLLER_H
