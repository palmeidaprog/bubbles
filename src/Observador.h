/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */



#ifndef BUBBLES_OBSERVADOR_H
#define BUBBLES_OBSERVADOR_H

#include "EventoTipo.h"
#include "libs/boost/any.hpp"
#include "Observado.h"

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
