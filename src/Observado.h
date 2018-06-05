//
// Created by paulo on 6/5/18.
//

#ifndef BUBBLES_OBSERVADO_H
#define BUBBLES_OBSERVADO_H

#include <memory>
#include <vector>
#include "Observador.h"

namespace bolhas { namespace interfaces {
    class Observado {
        std::vector<Observador*> observadores;

    public:
        virtual Observado() = default;

        virtual ~Observado();

        void adicionarObservador(Observador *obs);
        void removerObservador(Observador *obs);

        template <typename T>
        void notificar(const T &tipo, Evento evento) {
            for(size_t i = 0; i < observadores.size(); i++) {
                observadores[i]->atualizar(*this, tipo, evento);
            }
        }
    };
}}

#endif //BUBBLES_OBSERVADO_H
