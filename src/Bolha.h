/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */

#ifndef BUBBLES_BOLHA_H
#define BUBBLES_BOLHA_H

#include <string>
#include "BolhaTipo.h"
#include "DificuldadeJogo.h"
#include "Delay.h"
#include <sstream>
#include <memory>

namespace bolhas { namespace model {
    class Bolha {
        int numero1, numero2, resultado, tamanho;
        DificuldadeJogo dificuldade;
        std::string impressao;
        std::unique_ptr<model::Delay> delay;

        enum Operacao {
            SOMA = 0, // 0
            SUBTRACAO = 1, // 1
            MULTIPLICACAO = 2, // 2
            DIVISAO = 3 // 3
        };
        Operacao operacao;
        int resposta();

    public:
        Bolha(DificuldadeJogo dificuldade, BolhaTipo tipo =
            BolhaTipo::NORMAL);
        virtual ~Bolha();

        void geraOperacao();
        bool verificaResposta(int n) const;
        const std::string &expressao();
        double modificadorNivel();
        int getTamanho();
        double tempoDeVida();
    };
}}



#endif //BUBBLES_BOLHA_H
