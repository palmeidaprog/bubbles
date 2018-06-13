/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */

#ifndef BUBBLES_CLICKAVEL_H
#define BUBBLES_CLICKAVEL_H

namespace bolhas { namespace interfaces {
    class Clickavel {

    public:
        virtual void click(int x, int y) const = 0;
    };
}}

#endif //BUBBLES_CLICKAVEL_H
