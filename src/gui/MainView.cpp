/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */

// main View

#include "MainView.h"

using namespace bolhas;

namespace bolhas { namespace gui {
    MainView::MainView() : LARGURA(0), ALTURA(0) {
        throw excecoes::JanelaException("Tamanho invalido de janela.");
    }

    MainView::MainView(int largura, int altura) : LARGURA(largura), 
            ALTURA(altura), stop(false) {
        janela = al_create_display(LARGURA, ALTURA);
        if(janela == NULL ) {
            throw excecoes::JanelaException("Erro ao abrir janela principal."
                    );
        }
        inicializar();
        
    }

    MainView::~MainView() {
        al_destroy_display(janela); // fecha janela
        al_destroy_event_queue(filaEventos);
    }

    void Main::View(inicializar) {

    }
    
    void MainView::ativarEventos() {
        filaEventos = al_create_event_queue();
        
        if(filaEventos == NULL) {
            throw excecoes::JanelaException("Erro ao criaar eventos.");        
        }

        al_register_event_source(filaEventos, al_get_display_event_source(janela));

        while(1) {
            ALLEGRO_EVENT evento;
            ALLEGRO_TIMEOUT tempo;
            al_init_timeout(&tempo, 0.01);
            bool temEventos = al_wait_for_event_until(filaEventos, &evento, 
                    &tempo);
            if(temEventos && ALLEGRO_EVENT_DISPLAY_CLOSE) {
                break;
            }
            
            al_attach_audio_stream_to_mixer(musica, al_get_default_mixer());
            al_set_audio_stream_playing(musica, true);

            ALLEGRO_BITMAP *imagem = al_load_bitmap("resources/images/bub.jpg"
                    );
            al_draw_bitmap(imagem, 0, 0, 0);
            al_flip_display();
        }
    }
}}
