/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */

#ifndef BUBBLES_PAINELSUPERIORVIEW_H
#define BUBBLES_PAINELSUPERIORVIEW_H

#include "Fonts.h"
#include <memory>
#include <cstdio>
#include "Color.h"

namespace bolhas { namespace gui {
    class PainelSuperiorView {
        int score;
        std::unique_ptr<model::Fonts> fonte;
        std::unique_ptr<model::Color> cor;

    public:
        PainelSuperiorView(const bolhas::model::Fonts &fonte);
        virtual ~PainelSuperiorView();

        void renderizar(int x, int y);
        int getScore() const;
        void setScore(int score);
    };
}}


#endif //BUBBLES_PAINELSUPERIORVIEW_H
