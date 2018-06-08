/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */

#ifndef BUBBLES_MUDAESTADO_H
#define BUBBLES_MUDAESTADO_H

#include "Clickavel.h"
#include "Estado.h"

namespace bolhas { namespace interfaces {
    class MudaEstado : public Clickavel {
        Estado estado;

    public:
        MudaEstado(Estado estado);

        void click(int x, int y) const override;
    };
}}


#endif //BUBBLES_MUDAESTADO_H
