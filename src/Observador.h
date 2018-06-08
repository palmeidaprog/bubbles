//
// Created by paulo on 6/5/18.
//

#ifndef BUBBLES_OBSERVADOR_H
#define BUBBLES_OBSERVADOR_H

#include "EventoTipo.h"
#include "Observado.h"
#include "libs/boost/any.hpp"

namespace bolhas { namespace interfaces {
    class Observado;
    class Observador {
        std::vector<Observado *> obs;

    protected:
        Observador() = default;

    public:
        virtual ~Observador();
        void adicionaObservado(Observado *obsvado);
        void removeObservado(Observado *obsvado);

        virtual void atualizar(const Observado &obs, const boost::any &objeto,
                               EventoTipo evento) = 0;
    };
}}

#endif //BUBBLES_OBSERVADOR_H
