//
// Created by paulo on 6/11/18.
//

#ifndef BUBBLES_SCORETIME_H
#define BUBBLES_SCORETIME_H

#include <memory>
#include <string>
#include "DificuldadeJogo.h"

namespace bolhas { namespace model {
    class ScoreTime {
        static std::shared_ptr<ScoreTime> instance;
        int score = 0;
        DificuldadeJogo dificuldade;
        double time = 300;
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
