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
#include <ctime>


using std::cerr;
using std::endl;
using std::cout;
using namespace bolhas;

void iniciar(gui::MainView &mainView);

int main(int argc, char** argv) {
    srand(time(nullptr));

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
    while(mainView.getEstado() != Estado::SAIR) {
        ALLEGRO_EVENT_QUEUE *filaEventos = mainView.getEventos();
        ALLEGRO_EVENT evento;
        ALLEGRO_TIMEOUT tempo;

        // loop de leitura de eventos
        bool temEventos = true;
        while(temEventos) {
            al_init_timeout(&tempo, (double) 1 / 500);
            temEventos = al_wait_for_event_until(filaEventos, &evento,
                                                      &tempo);
            if (temEventos) {
                if(evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
                    exit(0);
                } else if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
                    if(mainView.click(x, y)) {
                        break;
                    }
                } else if(evento.type == ALLEGRO_EVENT_KEY_UP) {
                    if(gui::EntradaDados::getInstance() != nullptr) {
                        switch (evento.keyboard.keycode) {
                            case ALLEGRO_KEY_9:
                                gui::EntradaDados::getInstance()
                                    ->addTexto('9');
                                break;
                            case ALLEGRO_KEY_8:
                                gui::EntradaDados::getInstance()
                                    ->addTexto('8');
                                break;
                            case ALLEGRO_KEY_7:
                                gui::EntradaDados::getInstance()
                                    ->addTexto('7');
                                break;
                            case ALLEGRO_KEY_6:
                                gui::EntradaDados::getInstance()
                                    ->addTexto('6');
                                break;
                            case ALLEGRO_KEY_5:
                                gui::EntradaDados::getInstance()
                                    ->addTexto('5');
                                break;
                            case ALLEGRO_KEY_4:
                                gui::EntradaDados::getInstance()
                                    ->addTexto('4');
                                break;
                            case ALLEGRO_KEY_3:
                                gui::EntradaDados::getInstance()
                                    ->addTexto('3');
                                break;
                            case ALLEGRO_KEY_2:
                                gui::EntradaDados::getInstance()
                                    ->addTexto('2');
                                break;
                            case ALLEGRO_KEY_1:
                                gui::EntradaDados::getInstance()
                                    ->addTexto('1');
                                break;
                            case ALLEGRO_KEY_0:
                                gui::EntradaDados::getInstance()
                                    ->addTexto('0');
                                break;
                            case ALLEGRO_KEY_BACKSPACE:
                                gui::EntradaDados::getInstance()
                                    ->removeTexto();
                                break;
                            case ALLEGRO_KEY_PAD_ENTER:
                                gui::EntradaDados::getInstance()
                                    ->enter();
                                cout << "ENTER"
                                     << endl;
                                break;
                            case ALLEGRO_KEY_ENTER:
                                gui::EntradaDados::getInstance()
                                    ->enter();
                                cout << "ENTER"
                                        << endl;
                                break;
                        }
                    }
                }
            }
        }

        x = evento.mouse.x;
        y = evento.mouse.y;

        time_point<system_clock, nanoseconds> p1 =
                std::chrono::system_clock::now();
        using namespace std::chrono;

        //mainView.renderizaTela(evento.mouse.x, evento.mouse.y);
        mainView.renderizaTela(x, y);
        time_point<system_clock, nanoseconds> p2 = system_clock::now();
        auto p = duration<double>(p2 - p1);
        al_rest(0.015 - p.count());
        cout << p.count() << endl;
        al_flip_display();
    }
}

