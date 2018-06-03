//
// Created by Paulo Roberto Almeida Filho on 5/31/18.
//

#ifndef BUBBLES_MOVEFONTS_H
#define BUBBLES_MOVEFONTS_H

#include "Fonts.h"

namespace bolhas { namespace animation {
    class ZoomFont {
        std::unique_ptr<model::Fonts> font;
        int min, max, crescimentoFonte, framesDelay, tamanho;
    public:
        ZoomFont(model::Fonts *font);
        virtual ~ZoomFont();

        //--Get/Set-----------------------------------------------------------
        const model::Fonts& getFont() const;
        void setFont(const model::Fonts& f);
        int getMin() const;
        void setMin(int min);
        int getMax() const;
        void setMax(int max);
        int getCrescimentoFonte() const;
        void setCrescimentoFonte(int crescimentoFonte);
        int getFramesDelay() const;
        void setFramesDelay(int framesDelay);

        void reset();




    };
}}

#endif //BUBBLES_MOVEFONTS_H
