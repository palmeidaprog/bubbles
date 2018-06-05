//
// Created by paulo on 6/5/18.
//

#ifndef BUBBLES_OBSERVADOR_H
#define BUBBLES_OBSERVADOR_H

#include "Evento.h"
#include "Observado.h"

namespace bolhas { namespace interfaces {
    class Observador {
        std::vector<Observado *> obs;
        explicit Observador() = default;

    public:
        virtual ~Observador();
        void adicionaObservado(Observado *obsvado);
        void removeObservado(Observado *obsvado);

        template <typename T>
        virtual void atualizar(const Observado &obs, const T &tipo, Evento
            evento) = 0;
    };
}}

#endif //BUBBLES_OBSERVADOR_H
