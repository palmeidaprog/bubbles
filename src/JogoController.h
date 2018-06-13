/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */


#ifndef BUBBLES_JOGOCONTROLLER_H
#define BUBBLES_JOGOCONTROLLER_H

#include "JogoView.h"
#include "BolhasController.h"

namespace bolhas { namespace gui {
    class JogoView;
    class JogoController {
        std::shared_ptr<JogoView> view;
        std::unique_ptr<model::BolhasController> bolhas;
        std::unique_ptr<model::Delay> delay;
        int score, nivel;
        model::DificuldadeJogo dificuldade;
        std::unique_ptr<model::Delay> segundos;

    public:
        JogoController(bolhas::gui::JogoView *view);
        virtual ~JogoController();
        void adicionaBolha();
        int getScore() const;
        void setScore(int score);
        int getNivel() const;
        void setNivel(int nivel);
        void renderizaBolhas(int x, int y);
        model::BolhasController *getBolhas();
        bool click(int x, int y);
    };
}}

#endif //BUBBLES_JOGOCONTROLLER_H
