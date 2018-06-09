/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */

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
        double getIntervalo() const;
        void setIntervalo(double intervalo);

        void parar() override;
        bool animacao() override;
    };
}}

#endif //BUBBLES_MOVEFONTS_H
