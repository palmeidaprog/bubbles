//
// Created by Paulo Roberto Almeida Filho on 6/8/18.
//

#ifndef BUBBLES_MUDAESTADO_H
#define BUBBLES_MUDAESTADO_H

#include "Clickavel.h"
#include "Estado.h"

namespace bolhas { namespace interfaces {
    class MudaEstado : public Clickavel {
        Estado estado;

    public:
        MudaEstado(Estado estado);

        void click() const override;
    };
}}


#endif //BUBBLES_MUDAESTADO_H
