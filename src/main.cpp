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
#include <chrono>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <iostream>


using std::cerr;
using std::endl;
using std::cout;
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
    int x = 0, y = 0;

    // loop do programa
    while(true) {
        ALLEGRO_EVENT_QUEUE *filaEventos = mainView.getEventos();
        ALLEGRO_EVENT evento;
        ALLEGRO_TIMEOUT tempo;
        //al_uninstall_mouse();

        //al_rest((double) 1 / 60);
        // loop de leitura de eventos
        bool temEventos = true;
        while(temEventos) {
            al_init_timeout(&tempo, (double) 1 / 500);
            temEventos = al_wait_for_event_until(filaEventos, &evento,
                                                      &tempo);
            //bool temEventos = al_get_next_event(filaEventos, &evento);

            if (temEventos) {
                if(evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
                    exit(0);
                } else if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
                    if(mainView.click(x, y)) {
                        break;
                    }
                }
            }

            /*else if ((evento.mouse.x < x + 5 && evento.mouse.x > x - 5) ||
                       (evento.mouse.x < y + 5 && evento.mouse.y > y - 5)) {
                continue;
            }*/
        }

        x = evento.mouse.x;
        y = evento.mouse.y;

        time_point<system_clock, nanoseconds> p1 =
                std::chrono::system_clock::now();
        using namespace std::chrono;

        mainView.renderizaTela(evento.mouse.x, evento.mouse.y);
        //mainView.renderizaTela(x, y);
        time_point<system_clock, nanoseconds> p2 = system_clock::now();
        auto p = duration<double>(p2 - p1);
        cout << p.count() << endl;
        al_flip_display();
    }
}

