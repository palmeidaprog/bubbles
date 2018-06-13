/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */

#include "MainController.h"

namespace bolhas { namespace gui {
    
    MainController::MainController(const MainView &view_) : view(view_)  {
    }

    MainController::~MainController() {
    }

    /*void MainController::loop() {
        while(true) {
            ALLEGRO_EVENT_QUEUE *filaEventos = view.getEventos();
            ALLEGRO_EVENT evento;
            ALLEGRO_TIMEOUT tempo;
            al_init_timeout(&tempo, 1 / 60);
            bool temEventos = al_wait_for_event_until(filaEventos, &evento, 
                    &tempo);
            if(temEventos && ALLEGRO_EVENT_DISPLAY_CLOSE) {
                break;
            }
            
            ALLEGRO_BITMAP *imagem = al_load_bitmap(
                "../resources/images/unders.jpg");
            if(imagem != NULL) {
                al_draw_bitmap(imagem, 0, 0, 0);
            }
            al_flip_display();
        }
    }*/
}}

