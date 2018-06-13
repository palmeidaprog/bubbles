/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */
#include "Delay.h"

bolhas::model::Delay::Delay(double delaySegundos) :
        delaySegundos(delaySegundos), close(false) {
    inicio = std::chrono::system_clock::now();
}

bolhas::model::Delay::~Delay() {
}

const bool bolhas::model::Delay::ready() {
    time_point<system_clock, nanoseconds> agora = std::chrono::system_clock::now();
    std::chrono::duration<double> passados = agora - inicio;
    if(passados < delaySegundos) {
        if(passados > delaySegundos * 0.75) {
            close = true;
        }
        return false;
    }
    inicio = std::chrono::system_clock::now();
    return true;
}

double bolhas::model::Delay::getDelay() const {
    return delaySegundos.count();
}

void
bolhas::model::Delay::setDelay(double delay) {
    Delay::delaySegundos = duration<double>(delay);
}

bool bolhas::model::Delay::isClose() const {
    return close;
}
