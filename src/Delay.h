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
        //std::chrono::time_point<duration<double>> inicio;
        std::chrono::duration<double> delay;

    public:
        Delay(double delay);
        virtual ~Delay();

        const std::chrono::duration<double> &getDelay() const;
        void setDelay(const std::chrono::duration<double> &delay);
        const bool ready();
    };
}}


#endif //BUBBLES_DELAY_H
