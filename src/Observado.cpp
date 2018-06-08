/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */

#include <algorithm>
#include "Observado.h"


void bolhas::interfaces::Observado::adicionarObservador(Observador *obs) {
    observadores.push_back(obs);
    obs->adicionaObservado(this);
}

void bolhas::interfaces::Observado::removerObservador(Observador *obs) {
    auto rem = std::find(observadores.begin(), observadores.end(), obs);
    if(rem != observadores.end()) {
        observadores.erase(rem);
        obs->removeObservado(this);
    }
}

bolhas::interfaces::Observado::~Observado() {
    for(size_t i = 0; i < observadores.size(); i++) {
        observadores[i]->removeObservado(this);
    }
}

template <typename T>
void bolhas::interfaces::Observado::notificar(const T &tipo, EventoTipo
        evento) {
    for(size_t i = 0; i < observadores.size(); i++) {
        observadores[i]->atualizar(*this, tipo, evento);
    }
}
