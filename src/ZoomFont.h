//
// Created by Paulo Roberto Almeida Filho on 5/31/18.
//

#ifndef BUBBLES_MOVEFONTS_H
#define BUBBLES_MOVEFONTS_H

#include "Fonts.h"
#include "Delay.h"
#include "EfeitoFonte.h"
#include <memory>


namespace bolhas { namespace animation {
    class ZoomFont : public EfeitoFonte {
        model::Fonts *font;
        int min, max, crescimentoFonte, tamanho, mult;
        std::unique_ptr<model::Delay> intervalo;



    public:
        ZoomFont(model::Fonts *font);

        virtual ~ZoomFont();

        //--Get/Set-----------------------------------------------------------
        const model::Fonts *getFont() const;
        void setFont(model::Fonts *f);
        int getMin() const;
        void setMin(int min);
        int getMax() const;
        void setMax(int max);
        int getCrescimentoFonte() const;
        void setCrescimentoFonte(int crescimentoFonte);
        std::unique_ptr<model::Delay> &getIntervalo();

        void parar() override;
        void animacao() override;
    };
}}

#endif //BUBBLES_MOVEFONTS_H
