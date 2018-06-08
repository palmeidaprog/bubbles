/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */

#ifndef BUBBLES_EFEITOS_H
#define BUBBLES_EFEITOS_H

namespace bolhas { namespace animation {
    class EfeitoFonte {

    public:
        virtual void parar() = 0;
        virtual void animacao() = 0;
    };
}}


#endif //BUBBLES_EFEITOS_H
