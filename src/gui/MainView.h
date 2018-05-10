/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */


#ifndef MAINVIEW_H // Whats - Ctype - ying
#define MAINVIEW_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_audio.h> 
#include <allegro5/allegro_acodec.h>
#include "../excecoes/JanelaException.h"
#include "MainController.h"

namespace bolhas { namespace gui {
    class MainView {
        ALLEGRO_DISPLAY *janela;
        ALLEGRO_EVENT_QUEUE *filaEventos;
        ALLEGRO_AUDIO_STREAM *musica;
        ALLEGRO_SAMPLE *sample;
        MainController controller;
        const int LARGURA;
        const int ALTURA;
        bool stop;

        void incializar();  
        void ativarEventos();      
        
    public:
        MainView();
        MainView(int largura, int altura);
        virtual ~MainView();
        

        const ALLEGRO_DISPLAY *getJanela() const {
            return janela;
        }
        
        const int getAltura() {
            return ALTURA;
        }
        
        const int getLargura() {
            return LARGURA;
        }
       
        
    };
}}

#endif /* MAINVIEW_H */
