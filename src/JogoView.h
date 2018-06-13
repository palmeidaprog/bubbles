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
#include <cstdio>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_native_dialog.h>
#include "PainelSuperiorView.h"
#include "JogoController.h"
#include "BaseView.h"
#include "MainView.h"
#include "ZoomIn.h"
#include "ScoreTime.h"
#include "EntradaDados.h"


namespace bolhas { namespace gui {
    class JogoController;
    class JogoView : public BaseView {
        std::unique_ptr<EntradaDados> dados;
        std::shared_ptr<model::ScoreTime> score;
        std::unique_ptr<JogoController> controller;
        std::shared_ptr<MainView> mainV;
        std::shared_ptr<model::Fonts> fonte, numbers;
        std::unique_ptr<animation::EfeitoFonte> efeitoFonte;
        std::unique_ptr<PainelSuperiorView> painel;
        int xFundo, xSource, mult;
        float cor, cor2, trans;
        std::string texto;

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
        bool click(int x, int y);
    };
}}

#endif //BUBBLES_JOGOVIEW_H
