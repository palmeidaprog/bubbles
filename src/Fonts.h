/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */

#ifndef BUBBLES_FONTS_H
#define BUBBLES_FONTS_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <string>

namespace bolhas { namespace model {
    class Fonts {
        ALLEGRO_FONT *pointer;
        std::string nome;
        int tamanho;
        bool trueType;

    public:
        Fonts(const model::Fonts *fonte);
        Fonts(const model::Fonts &fonte);
        Fonts(const std::string &nome, int tamanho, bool trueType = false);
        virtual ~Fonts();

        ALLEGRO_FONT *getPointer() const;
        const std::string &getFontNome() const;
        void changeFont(const std::string &nome, bool trueType = false);
        void changeFont(const std::string &nome, int tamanho, bool
                trueType = false);
        int getTamanho() const;
        void setTamanho(int tamanho);
        void changeFont();
    };
}}


#endif //BUBBLES_FONTS_H
