//
// Created by paulo on 6/5/18.
//

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
