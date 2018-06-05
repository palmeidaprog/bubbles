/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */

#include "MainView.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <iostream>

using std::cerr;
using std::endl;
using namespace bolhas;

void iniciar(gui::MainView &mainView);

int main(int argc, char** argv) {
    // inicializa Allegro 
    if(!al_init()) {
        cerr << "Falha na inicialização do Allegro" << endl;
        return -1;
    }
     
    // cria janela principal
    try {
        gui::MainView mainView(1280, 720);
        iniciar(mainView);
    } catch(const excecoes::JanelaException &e) {
        cerr << e.what() << endl;
        return -1;
    }

    return 0;
}

void iniciar(gui::MainView &mainView) {
    while(true) {
            ALLEGRO_EVENT_QUEUE *filaEventos = mainView.getEventos();
            ALLEGRO_EVENT evento;
            ALLEGRO_TIMEOUT tempo;
            //al_rest((double) 1 / 60);
            al_init_timeout(&tempo, (double) 1 / 500);
            bool temEventos = al_wait_for_event_until(filaEventos, &evento, 
                    &tempo);
            if(temEventos && evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
                break;
            }
            //int x, y;
            //al_get_mouse_cursor_position(&x, &y);
            mainView.renderizaTela(evento.mouse.x, evento.mouse.y);
            al_flip_display();
    }
}

