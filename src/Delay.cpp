/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */
#include "Delay.h"

bolhas::model::Delay::Delay() : frames(0) {}

bolhas::model::Delay::~Delay() {
}

const bool bolhas::model::Delay::test(int delay) {
    if(delay == frames) {
        frames = 1;
        return true;
    } else {
        ++frames;
        return false;
    }
}
