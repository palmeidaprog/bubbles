/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */

#include <allegro5/allegro_audio.h>
#include "BaseView.h"

void bolhas::gui::BaseView::fundoDeTela(const char *nome) {
    fundo = al_load_bitmap(nome);
    fundoDeTela();
}

void bolhas::gui::BaseView::fundoDeTela() {
    if(fundo != nullptr) {
        al_draw_bitmap(fundo, 0, 0, 0);
    }
}

bolhas::gui::BaseView::BaseView() : musica(nullptr), sample(nullptr) {

}

bolhas::gui::BaseView::~BaseView() {
    al_destroy_bitmap(fundo);
    al_destroy_audio_stream(musica);
    al_destroy_sample(sample);
    al_destroy_sample(efeito);
}

void bolhas::gui::BaseView::setMusica(const std::string &musicaArq) {
    this->musicaArq = musicaArq;
    sample = al_load_sample(musicaArq.c_str());
}

void bolhas::gui::BaseView::setEfeito(const std::string &efeitoArq) {
    this->efeitoArq = efeitoArq;
    efeito = al_load_sample(efeitoArq.c_str());
}

void bolhas::gui::BaseView::playSom() const {
    al_play_sample(sample, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP, nullptr);
}

void bolhas::gui::BaseView::playEfeito() const {
    al_play_sample(efeito, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE, nullptr);
}

void bolhas::gui::BaseView::stopSom() const {
    al_stop_samples();
}

const std::string &bolhas::gui::BaseView::getMusica() const {
    return musicaArq;
}

ALLEGRO_SAMPLE *bolhas::gui::BaseView::getSample() {
    return sample;
}

ALLEGRO_BITMAP *bolhas::gui::BaseView::getFundo() {
    return fundo;
}
