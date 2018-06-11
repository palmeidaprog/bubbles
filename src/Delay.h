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
        bool close = false;

    public:
        Delay(double delay);
        virtual ~Delay();

        double getDelay() const;
        void setDelay(double delay);
        const bool ready();
        bool isClose() const;
    };
}}


#endif //BUBBLES_DELAY_H
