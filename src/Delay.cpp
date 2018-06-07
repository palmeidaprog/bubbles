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
        delaySegundos(delaySegundos) {
    inicio = std::chrono::system_clock::now();
}

bolhas::model::Delay::~Delay() {
}

const bool bolhas::model::Delay::ready() {
    TimePoint agora = std::chrono::system_clock::now();
    std::chrono::duration<double> passados = agora - inicio;
    if(passados < delaySegundos) {
        return false;
    }
    inicio = std::chrono::system_clock::now();
    return true;
}

const std::chrono::duration<double> &bolhas::model::Delay::getDelay() const {
    return delaySegundos;
}

void
bolhas::model::Delay::setDelay(const std::chrono::duration<double> &delay) {
    Delay::delaySegundos = delay;
}
