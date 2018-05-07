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


namespace bolhas { namespace gui {
    class MainView {
        ALLEGRO_DISPLAY *janela = NULL;
        ALLEGRO_EVENT_QUEUE *filaEventos = NULL;
        ALLEGRO_AUDIO_STREAM *musica = NULL;
        ALLEGRO_SAMPLE *sample = NULL;
        MainController controller;
        const int LARGURA;
        const int ALTURA;
        bool stop;

        void incializar();        
        
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

