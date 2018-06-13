/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */

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
        int valorMin, valorMax, tamanho, crescimentoFonte;
        float percentual;
        std::unique_ptr<model::Delay> intervalo;

    public:

        ZoomIn(model::Fonts *font, model::Colors corOriginal,
               model::Colors cor, int valorMax, int tamanho);
        virtual ~ZoomIn();

        const model::Color &getCor() const;
        int getValorMax() const;
        void setValorMax(int valorMax);
        int getCrescimentoFonte() const;
        void setCrescimentoFonte(int crescimentoFonte);
        double getIntervalo() const;
        void setIntervalo(double intervalo);
        void parar() override;
        bool animacao() override;
    };
}}

#endif //BUBBLES_ZOOMIN_H
