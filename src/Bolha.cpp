//
// Created by paulo on 6/10/18.
//


#include "Bolha.h"

bolhas::model::Bolha::Bolha(DificuldadeJogo dificuldade,
                            bolhas::model::BolhaTipo tipo) {
    this->dificuldade = dificuldade;
    tempoDeVida();
    geraOperacao();
}

void bolhas::model::Bolha::geraOperacao() {
    int resto;
    int op = 0;

    do { // evita operacoes de divisao com resto
        switch (dificuldade) {
            case DificuldadeJogo::FACIL:
                numero1 = rand() % 4;
                numero2 = rand() % 3 + 1;
                op += rand() % 2;
                break;
            case DificuldadeJogo::NORMAL:
                numero1 = rand() % 6;
                numero2 = rand() % 5 + 1;
                op += rand() % 4;
                break;
            default: // DIFICIL
                numero1 = rand() % 10;
                numero2 = rand() % 9 + 1;
                op += rand() % 4;
                break;
        }
        operacao = (Operacao) op;
    } while(numero2 > numero1 || (operacao == DIVISAO && numero1 % numero2));


    resultado = resposta();
}



int bolhas::model::Bolha::resposta() {
    switch(operacao) {
        case SOMA:
            return numero1 + numero2;
        case SUBTRACAO:
            return numero1 - numero2;
        case MULTIPLICACAO:
            return numero1 * numero2;
        default: // divisao
            return numero1 / numero2;
    }
}

bool bolhas::model::Bolha::verificaResposta(int n) const {
    return (resultado == n);
}

const std::string &bolhas::model::Bolha::expressao() {
    std::stringstream is;
    is << numero1 ;
    switch(operacao) {
        case SOMA:
            is << "+";
            break;
        case SUBTRACAO:
            is << "-";
            break;
        case MULTIPLICACAO:
            is << "x";
            break;
        default:
            is << ":";
            break;
    }
    is << numero2;
    impressao = is.str();
    return impressao;
}

double bolhas::model::Bolha::tempoDeVida() {
    double tempo;
    switch(dificuldade) {
        case DificuldadeJogo::FACIL:
            tempo = 16 * modificadorNivel();
            break;
        case DificuldadeJogo::NORMAL:
            tempo = 8 * modificadorNivel();
            break;
        default:
            tempo = 5 * modificadorNivel();
    }
    delay = std::unique_ptr<model::Delay> (new model::Delay(tempo));
    return tempo;
}

double bolhas::model::Bolha::modificadorNivel() {
    // todo: desenvolver algoritmo para achar um coeficiente de acordo
    // com nivel
    return 1;
}

int bolhas::model::Bolha::getTamanho() {
    if(delay->ready()) {
        ++tamanho;
    }
    return tamanho;
}

bolhas::model::Bolha::~Bolha() {

}


