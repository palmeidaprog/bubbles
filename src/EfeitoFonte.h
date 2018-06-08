//
// Created by Paulo Roberto Almeida Filho on 6/7/18.
//

#ifndef BUBBLES_EFEITOS_H
#define BUBBLES_EFEITOS_H

namespace bolhas { namespace animation {
    class EfeitoFonte {

    public:
        virtual void parar() = 0;
        virtual void animacao() = 0;
    };
}}


#endif //BUBBLES_EFEITOS_H
