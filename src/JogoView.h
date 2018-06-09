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
#include "JogoController.h"
#include "BaseView.h"
#include "MainView.h"

namespace bolhas { namespace gui {
    class JogoView : public BaseView {
        std::unique_ptr<JogoController> controller;
        std::shared_ptr<MainView> main;
        std::unique_ptr<model::Fonts> fonte, numbers;
        std::unique_ptr<animation::EfeitoFonte> efeitoFonte;
        int xFundo, xSource, mult = 1;
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
    };
}}

#endif //BUBBLES_JOGOVIEW_H
