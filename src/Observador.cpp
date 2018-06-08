/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */

#include <algorithm>
#include "Observador.h"

bolhas::interfaces::Observador::~Observador() {
    for(size_t i = 0; i < obs.size(); i++) {
        obs[i]->removerObservador(this);
    }
}

void bolhas::interfaces::Observador::adicionaObservado(
        bolhas::interfaces::Observado *obsvado) {
    obs.push_back(obsvado);
}

void bolhas::interfaces::Observador::removeObservado(
        bolhas::interfaces::Observado *obsvado) {
    auto rem = std::find(obs.begin(), obs.end(), obsvado);
    if(rem != obs.end()) {
        obs.erase(rem);
    }
}
