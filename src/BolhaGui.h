//
// Created by paulo on 6/10/18.
//

#ifndef BUBBLES_BOLHAGUI_H
#define BUBBLES_BOLHAGUI_H


#include <allegro5/bitmap.h>
#include "Bolha.h"
#include "BolhasController.h"
#include "AcaoBolha.h"
#include "Fonts.h"
#include "EntradaDados.h"
#include "Color.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>

namespace bolhas { namespace model {
    class BolhasController;
    class BolhaGui {
        std::unique_ptr<model::Bolha> data;
        std::shared_ptr<BolhasController> controller;
        std::unique_ptr<model::Delay> delay, tempoDeVida, anima, explode,
                seca;
        std::unique_ptr<model::Fonts> fonte;
        std::unique_ptr<model::Color> cor;
        ALLEGRO_BITMAP *imagem;
        int posX, posY, tamanho = 1, spriteNum = 1, moveX, moveY;
        float scale = 0.4;
        bool animate = false;
        AcaoBolha acao;

        void checarLimites();
        void animacaoSecando();
        void animacaoExplodindo();

    public:
        BolhaGui(BolhasController *controller, int posX, int posY, AcaoBolha
                acao = AcaoBolha::NORMAL);
        virtual ~BolhaGui();

        AcaoBolha getAcao() const;
        void renderizar(int x, int y);
        Bolha *getData();
        bool click(int x, int y);
    };
}}


#endif //BUBBLES_BOLHAGUI_H
