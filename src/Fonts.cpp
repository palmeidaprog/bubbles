/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */

#include "Fonts.h"

ALLEGRO_FONT *bolhas::model::Fonts::getPointer() const {
    return pointer;
}

const std::string &bolhas::model::Fonts::getFontNome() const {
    return nome;
}

int bolhas::model::Fonts::getTamanho() const {
    return tamanho;
}

void bolhas::model::Fonts::setTamanho(int tamanho) {
    Fonts::tamanho = tamanho;
}

bolhas::model::Fonts::Fonts(const std::string &nome, int tamanho, bool
    trueType) : pointer(nullptr), nome(nome), tamanho(tamanho),
    trueType(trueType) {
    changeFont(nome, tamanho, trueType);
}

void bolhas::model::Fonts::changeFont() {
    changeFont(nome, tamanho, trueType);
}

bolhas::model::Fonts::~Fonts() {
    if(pointer) {
        al_destroy_font(pointer);
    }
}

void bolhas::model::Fonts::changeFont(const std::string &nome, bool
        trueType) {
    changeFont(nome, Fonts::tamanho, trueType);
}

void bolhas::model::Fonts::changeFont(const std::string &nome, int tamanho,
        bool trueType) {
    this->nome = nome;
    this->trueType = trueType;
    this->tamanho = tamanho;

    if(pointer != NULL) {
        al_destroy_font(pointer);
        pointer = NULL;
    }
    if(trueType) {
        pointer = al_load_ttf_font(nome.c_str(), tamanho, 0);
    } else {
        pointer = al_load_font(nome.c_str(), tamanho, 0);
    }
}

bolhas::model::Fonts::Fonts(const bolhas::model::Fonts *fonte) : pointer
        (NULL), nome(fonte->nome), tamanho(fonte->tamanho), trueType
        (fonte->trueType) {
    changeFont(nome, tamanho, trueType);
}

bolhas::model::Fonts::Fonts(const bolhas::model::Fonts &fonte): pointer
        (NULL), nome(fonte.nome), tamanho(fonte.tamanho), trueType
        (fonte.trueType) {
    changeFont(nome, tamanho, trueType);
}
