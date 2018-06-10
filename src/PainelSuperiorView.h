//
// Created by paulo on 6/10/18.
//

#ifndef BUBBLES_PAINELSUPERIORVIEW_H
#define BUBBLES_PAINELSUPERIORVIEW_H

#include <Fonts.h>
#include <memory>
#include <Color.h>

namespace bolhas { namespace gui {
    class PainelSuperiorView {
        int score = 0;
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
