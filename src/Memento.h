/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */

#ifndef BUBBLES_MEMENTO_H
#define BUBBLES_MEMENTO_H

#include "Estado.h"

namespace bolhas { namespace interfaces {
    class Memento {
        virtual void getEstado() = 0;
        virtual void setEstado(Estado estado) = 0;
    };
}}


#endif //BUBBLES_MEMENTO_H
