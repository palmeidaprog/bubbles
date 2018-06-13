/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */

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
        int posX, posY, tamanho, spriteNum, moveX, moveY;
        float scale;
        bool animate;
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
