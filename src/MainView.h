/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */


#ifndef MAINVIEW_H 
#define MAINVIEW_H

#include <iostream>
#include "Estado.h"
#include "Janela.h"
#include "JanelaException.h"
#include "MenuView.h"
#include "MainController.h"
#include "Fonts.h"
#include "Memento.h"
#include "MenuItem.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_audio.h> 
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <vector>

using std::cerr;
using std::endl;

namespace bolhas { namespace gui {
    class MainController;
    class MenuView;
class MainView : public Janela, public interfaces::Memento<Estado> {
        model::Fonts *fonte;
        ALLEGRO_EVENT_QUEUE *filaEventos;
        ALLEGRO_AUDIO_STREAM *musica;
        ALLEGRO_SAMPLE *sample;
        ALLEGRO_BITMAP *fundo;
        bool stop;
        int canaisAudio = 4;
        std::string musicaArq;
        std::string titulo;
        std::string imagemArq;
        MainController *controller;
        MenuView *menu;
        Estado estado;
        static std::shared_ptr<MainView> instance;

        void inicializaSom();
        void inicializaTeclado();
        void inicializaImagem() const;
        void inicializaFont();
        void inicializaEventos();
        void inicializaMouse();

        
    public:
        MainView(int largura, int altura);
        ~MainView() override;

        static std::shared_ptr<MainView> getInstance() {
            return instance;
        }

        model::Fonts getFonte() const;
        void setMusica(const std::string &musicaArq);
        void setTitulo(const std::string &titulo);
        void setImagem(const std::string &imagemArq);
        void playSom() const;
        ALLEGRO_EVENT_QUEUE *getEventos() const;
        void fundoDeTela(const char *nome);
        void fundoDeTela() const;
        void escondeMenu();
        void renderizaTela(int x, int y);
        void mostraMenu(int x, int y);
        const std::string &getNomeFonte() const;
        bool click(int x, int y);

        Estado getEstado() const override {
            return estado;
        }

        void setEstado(Estado estado) override {
            this->estado = estado;
        }
    };
}}

#endif /* MAINVIEW_H */

