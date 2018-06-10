/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */

#ifndef BUBBLES_JOGOVIEW_H
#define BUBBLES_JOGOVIEW_H


#include <memory>
#include <allegro5/allegro_font.h>
#include <PainelSuperiorView.h>
#include "JogoController.h"
#include "BaseView.h"
#include "MainView.h"
#include "ZoomIn.h"

namespace bolhas { namespace gui {
    class JogoController;
    class JogoView : public BaseView {
        std::unique_ptr<JogoController> controller;
        std::shared_ptr<MainView> mainV;
        std::shared_ptr<model::Fonts> fonte, numbers;
        std::unique_ptr<animation::EfeitoFonte> efeitoFonte;
        std::unique_ptr<PainelSuperiorView> painel;
        int xFundo, xSource, mult = 1;
        float cor = 0.1, cor2 = 1, trans = 0.2;
        std::string texto = "3";

        enum class InGame {
            DISPLAYING, JOGANDO
        };
        InGame ingame;

        bool contagem();

    public:
        JogoView();
        virtual ~JogoView();

        void fundoDeTela(const char *nome) override;
        void fundoDeTela() override;
        void renderizar(int x, int y);
        void cabecalho(int x, int y);
    };
}}

#endif //BUBBLES_JOGOVIEW_H
