/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */


#include "BaseView.h"
#include <chrono>
#include <iostream>

void bolhas::gui::BaseView::fundoDeTela(const char *nome) {

    using namespace std::chrono;
    time_point<system_clock, nanoseconds> p1 =
        std::chrono::system_clock::now();

    fundo = al_load_bitmap(nome);
    std::cout << "reload" << std::endl;

    time_point<system_clock, nanoseconds> p2 = system_clock::now();
    auto p = duration<double>(p2 - p1);
    std::cout << p.count() << std::endl;


    fundoDeTela();
}

void bolhas::gui::BaseView::fundoDeTela() {
    if(fundo != nullptr) {
        al_draw_bitmap(fundo, 0, 0, 0);
    }
}

bolhas::gui::BaseView::BaseView() : musica(nullptr), sample(nullptr),
	canaisAudio(4) {

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
    std::string s = "resources/sons/pop2.wav";
    pop = al_load_sample(s.c_str());
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

void bolhas::gui::BaseView::playPop() const {
	ALLEGRO_SAMPLE_INSTANCE *instance = al_create_sample_instance(pop);
	al_attach_sample_instance_to_mixer(instance, al_get_default_mixer());
	al_set_sample_instance_playing(instance, true);
    al_play_sample_instance(instance);
}
