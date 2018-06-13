/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */

#ifndef BUBBLES_TRANSITION_H
#define BUBBLES_TRANSITION_H


namespace bolhas { namespace animation {
    class Transition {
    public:
        virtual bool animar() = 0;
    };
}}

#endif //BUBBLES_TRANSITION_H
