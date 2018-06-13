/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */

#include "ScoreTime.h"

std::shared_ptr<bolhas::model::ScoreTime> bolhas::model::ScoreTime::instance;

bolhas::model::ScoreTime::ScoreTime(bolhas::model::DificuldadeJogo
        dificuldade) : dificuldade(dificuldade), time(300), score(0) {
    instance =  std::shared_ptr<ScoreTime>(this);

}

bolhas::model::ScoreTime::~ScoreTime() {

}

void bolhas::model::ScoreTime::adicionaScore(int n)     {
    score += n;
}

int bolhas::model::ScoreTime::getScore() const {
    return score;
}

void bolhas::model::ScoreTime::adicionaTime(double segundos) {
    time = (time + segundos > 300) ? 300 : time + segundos;
}

void bolhas::model::ScoreTime::removeTime(double segundos) {
    time = (time - segundos < 1) ? 0 : time - segundos;
}

const std::string &bolhas::model::ScoreTime::mostraTime() {
    char str[6];
    int m, seg;
    m = static_cast<int>(time) / 60;
    seg = static_cast<int>(time) % 60;
	#if defined(WIN32) || defined(_WIN32)
    _snprintf_s(str, 6, _TRUNCATE, " %01d:%02d", m, seg);
	#else 
	snprintf(str, 6, " %01d:%02d", m, seg);
	#endif
    tempo = std::string(str);
    return tempo;
}

bool bolhas::model::ScoreTime::timeOver() const {
    return (time == 0);
}

void bolhas::model::ScoreTime::reset() {
    time = 300;
    score = 0;
}

void bolhas::model::ScoreTime::bolhaCerta() {
    score += 10;
    time += 10;
}

void bolhas::model::ScoreTime::bolhaErrada() {
    time -= 2;
}

void bolhas::model::ScoreTime::bolhaEstourada() {
    time -= 10;
}
