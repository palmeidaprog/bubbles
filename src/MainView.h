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
#include "Transition.h"
#include "BaseView.h"
#include "JogoView.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_audio.h> 
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <vector>
#include "ScoreTime.h"

using std::cerr;
using std::endl;

namespace bolhas { namespace gui {
    class MainController;
    class MenuView;
    class JogoView;
    class ScoreTime;
    class MainView : public Janela, public interfaces::Memento<Estado>, public
     BaseView {
        model::Fonts *fonte;
        ALLEGRO_EVENT_QUEUE *filaEventos;
        bool stop;
        std::string titulo;
        std::string imagemArq;
        MainController *controller;
        std::shared_ptr<JogoView> jogo;
        MenuView *menu;
        std::unique_ptr<animation::Transition> transition;
        Estado estado;
        int canaisAudio = 4;
        bool estadoMudado;
        static std::shared_ptr<MainView> instance;
        model::DificuldadeJogo dificuldade =
            model::DificuldadeJogo::NORMAL;
        std::shared_ptr<model::ScoreTime> scoreTime;

        void inicializaSom();
        void inicializaTeclado();
        void inicializaImagem() const;
        void inicializaFont();
        void inicializaEventos();
        void inicializaMouse();

        
    public:
        static std::shared_ptr<MainView> getInstance() {
            return instance;
        }

        MainView(int largura, int altura);
        ~MainView() override;

        model::Fonts getFonte() const;
        void setTitulo(const std::string &titulo);
        ALLEGRO_EVENT_QUEUE *getEventos() const;
        void escondeMenu();
        void renderizaTela(int x, int y);
        void mostraMenu(int x, int y);
        bool click(int x, int y);
        model::DificuldadeJogo getDificuldade() const;
        void setDificuldade(model::DificuldadeJogo dificuldade);
        Estado getEstado() const override {
            return estado;
        }

        void setEstado(Estado estado) override {
            this->estado = estado;
            estadoMudado = true;
        }
    };
}}

#endif /* MAINVIEW_H */

