/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */

#ifndef BUBBLES_DELAY_H
#define BUBBLES_DELAY_H

#include <chrono>

namespace bolhas { namespace model {
    class Delay {
        //std::chrono::duration tempo;
        int frames;


    public:
        Delay();
        virtual ~Delay();
        const bool test(int delay);
    };
}}


#endif //BUBBLES_DELAY_H
