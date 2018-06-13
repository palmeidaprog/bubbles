//
// Created by paulo on 6/11/18.
//

#ifndef BUBBLES_ENTRADADADOS_H
#define BUBBLES_ENTRADADADOS_H

#include <allegro5/bitmap.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <string>
#include <memory>
#include "Fonts.h"
#include "Color.h"

namespace bolhas { namespace gui {
    class EntradaDados {
        ALLEGRO_BITMAP *boneco, *balao;
        bool mostrando, enterPressionado;
        int posX, posY, balaoY, targetPosY,
            balaoX, targetBalaoY;
        std::string texto, resp;
        static std::shared_ptr<EntradaDados> instance;
        std::unique_ptr<model::Fonts> fonte;
        std::unique_ptr<model::Color> cor;

    public:
        static std::shared_ptr<EntradaDados> getInstance() {
            return instance;
        }

        EntradaDados();
        virtual ~EntradaDados();
        void setTexto(const std::string &texto);
        void addTexto(char c);
        void removeTexto();
        void mostraBalao(bool mostrando);
        bool isMostrando() const;
        int getResp();
        void renderiza(int x, int y);
        void enter();
        bool isEnter();
    };
}}


#endif //BUBBLES_ENTRADADADOS_H
