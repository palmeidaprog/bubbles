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

#include <iostream>
#include "MainController.h"
#include "../excecoes/JanelaException.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_audio.h> 
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>

using std::cerr;
using std::endl;


namespace bolhas { namespace gui {
    class MainView {
        ALLEGRO_DISPLAY *janela;
        ALLEGRO_BITMAP *imagem;
        ALLEGRO_EVENT_QUEUE *filaEventos;
        ALLEGRO_AUDIO_STREAM *musica;
        ALLEGRO_SAMPLE *sample;
        MainController *controller;
        const int LARGURA;
        const int ALTURA;
        bool stop;
        int canaisAudio = 4;
        std::string musicaArq;
        std::string titulo;
        std::string imagemArq;

        void incializar();  
        void ativarEventos();      
        void inicializaSom();
        void inicializaTeclado();
        void inicializaImagem();
        
    public:
        MainView(int largura, int altura);
        virtual ~MainView();
        
        void setMusica(const std::string &musicaArq);
        void setTitulo(const std::string &titulo);
        void setImagem(const std::string &imagemArq);
        void displayImagem(double x = 0, double y = 0, int flag = 0);

        const ALLEGRO_DISPLAY *getJanela() const {
            return janela;
        }
        
        const int getAltura() const {
            return ALTURA;
        }
        
        const int getLargura() const {
            return LARGURA;
        }    
    };
}}

#endif /* MAINVIEW_H */

