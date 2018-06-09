//
// Created by paulo on 6/9/18.
//

#ifndef BUBBLES_ZOOMIN_H
#define BUBBLES_ZOOMIN_H

#include "Delay.h"
#include "Fonts.h"
#include "EfeitoFonte.h"
#include "Color.h"
#include <memory>

namespace bolhas { namespace animation {
    class ZoomIn : public EfeitoFonte {
        model::Fonts *font;
        std::unique_ptr<model::Color> cor, corOriginal;
        int min, max, crescimentoFonte, tamanho;
        std::unique_ptr<model::Delay> intervalo;

    public:

        ZoomIn(model::Fonts *font, model::Colors corOriginal,
               model::Colors cor, int max, int tamanho);
        virtual ~ZoomIn();

        const model::Color &getCor() const;
        int getMax() const;
        void setMax(int max);
        int getCrescimentoFonte() const;
        void setCrescimentoFonte(int crescimentoFonte);
        double getIntervalo() const;
        void setIntervalo(double intervalo);
        void parar() override;
        bool animacao() override;
    };
}}

#endif //BUBBLES_ZOOMIN_H
