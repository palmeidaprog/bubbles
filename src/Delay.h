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

using std::chrono::time_point;
using std::chrono::nanoseconds;
using std::chrono::milliseconds;
using std::chrono::seconds;
using std::chrono::duration;
using std::chrono::system_clock;
using TimePoint = time_point<system_clock, nanoseconds>;

namespace bolhas { namespace model {
    class Delay {
        TimePoint inicio;
        duration<double> delaySegundos;

    public:
        Delay(double delay);
        virtual ~Delay();

        const std::chrono::duration<double> &getDelay() const;
        void setDelay(const std::chrono::duration<double> &delay);
        const bool ready();
    };
}}


#endif //BUBBLES_DELAY_H
