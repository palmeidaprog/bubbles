/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */

#ifndef BUBBLES_BASEVIEW_H
#define BUBBLES_BASEVIEW_H

#include <allegro5/bitmap.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <string>

namespace bolhas { namespace gui {
    class BaseView {
        ALLEGRO_BITMAP *fundo;
        std::string musicaArq, efeitoArq;
        int canaisAudio;
        ALLEGRO_AUDIO_STREAM *musica;
        ALLEGRO_SAMPLE *sample, *efeito, *pop;

    public:
        BaseView();
        virtual ~BaseView();

        virtual void fundoDeTela(const char *nome);
        ALLEGRO_BITMAP *getFundo();
        virtual void fundoDeTela();
        void setMusica(const std::string &musicaArq);
        void setEfeito(const std::string &efeitoArq);
        const std::string &getMusica() const;
        void playSom() const;
        void playEfeito() const;
        void stopSom() const;
        void playPop() const;
        ALLEGRO_SAMPLE *getSample();
    };
}}


#endif //BUBBLES_BASEVIEW_H
