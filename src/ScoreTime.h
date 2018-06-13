/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */

#ifndef BUBBLES_SCORETIME_H
#define BUBBLES_SCORETIME_H

#include <memory>
#include <cstdio>
#include <string>
#include "DificuldadeJogo.h"

namespace bolhas { namespace model {
    class ScoreTime {
        static std::shared_ptr<ScoreTime> instance;
        int score;
        DificuldadeJogo dificuldade;
        double time;
        std::string tempo;

    public:
        static std::shared_ptr<ScoreTime> getInstance() {
            return instance;
        }

        ScoreTime(DificuldadeJogo dificuldade);
        virtual ~ScoreTime();
        void adicionaScore(int n);
        int getScore() const;
        void adicionaTime(double segundos);
        void removeTime(double segundos);
        const std::string &mostraTime();
        bool timeOver() const;
        void reset();
        void bolhaCerta();
        void bolhaErrada();
        void bolhaEstourada();
    };
}}

#endif //BUBBLES_SCORETIME_H
