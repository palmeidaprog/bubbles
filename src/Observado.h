/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */

#ifndef BUBBLES_OBSERVADO_H
#define BUBBLES_OBSERVADO_H

#include <memory>
#include <vector>
#include "Observador.h"

namespace bolhas { namespace interfaces {
    class Observador;
    class Observado {
        std::vector<Observador*> observadores;

    public:
        Observado() = default;

        virtual ~Observado();

        void adicionarObservador(Observador *obs);
        void removerObservador(Observador *obs);

        template <typename T>
        void notificar(const T &tipo, EventoTipo evento);

    };
}}

#endif //BUBBLES_OBSERVADO_H
