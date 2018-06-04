//
// Created by Paulo Roberto Almeida Filho on 6/3/18.
//

#ifndef BUBBLES_MENUITEM_H
#define BUBBLES_MENUITEM_H

#include <string>
#include <memory>
#include "Color.h"
#include "Fonts.h"

namespace bolhas { namespace gui {
    class MenuItem {
        float x, y, largura, altura;
        int flag;
        std::string texto;
        std::unique_ptr<model::Color> cor, corSelecionada;
        std::unique_ptr<model::Fonts> fonte;
        bool ehSelecionado(int x, int y);

    public:
        MenuItem();
        MenuItem(const model::Fonts &fonte, const model::Colors &cor,
                 const model::Colors &corSelecionada, float x, float y,
                 int flag, std::string texto);
        virtual ~MenuItem();

        //--Setters/Gettters--------------------------------------------------
        float getX() const;
        void setX(float x);
        float getY() const;
        void setY(float y);
        float getLargura() const;
        void setLargura(float largura);
        float getAltura() const;
        void setAltura(float altura);
        int getFlag() const;
        void setFlag(int flag);
        const std::string &getTexto() const;
        void setTexto(const std::string &texto);
        const std::unique_ptr<model::Fonts> &getFonte() const;
        void setFonte(model::Fonts fonte);
        const model::Color &getCor() const;
        void setCor(std::unique_ptr<model::Color> cor);
        const model::Color &getCorSelecionada() const;
        void setCorSelectionada(std::unique_ptr<model::Color> corSelecionada);

        //--------------------------------------------------------------------

        void renderizar(int x, int y);
    };
}}


#endif //BUBBLES_MENUITEM_H
