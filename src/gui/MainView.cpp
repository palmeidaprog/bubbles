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
    MainView::MainView(int largura, int altura) : LARGURA(largura), 
            ALTURA(altura), janela(NULL), filaEventos(NULL),
            musica(NULL), sample(NULL), stop(false), musicaArq(
                "resources/sons/Space_Loop.wav"), titulo("Algebra Bolheana"),
                imagemArq("resources/images/bubl.jpg") {
        
        controller = new MainController(*this);
        
        inicializaSom();
        std::cout << "Som inicializado" << endl;
        inicializaTeclado();
        std::cout << "teclado inicializado" << endl;
        janela = al_create_display(LARGURA, ALTURA);
        if(janela == NULL) {
            throw excecoes::JanelaException("Erro ao abrir janela principal."
                    );
        }
        inicializaImagem();
        displayImagem();
        ativarEventos();
        std::cout << "Eventos inicializado" << endl;
        
    }

    MainView::~MainView() {
        al_destroy_audio_stream(musica);
        al_destroy_sample(sample);
        al_destroy_display(janela); // fecha janela
        al_destroy_event_queue(filaEventos);
    }



    void MainView::ativarEventos() {
        filaEventos = al_create_event_queue();
        
        if(filaEventos == NULL) {
            throw excecoes::JanelaException("Erro ao criaar eventos.");        
        }

        al_register_event_source(filaEventos, al_get_display_event_source(janela));

        while(1) {
            std::cout << "EM EVVENTOS inicializado" << endl;
            ALLEGRO_EVENT evento;
            ALLEGRO_TIMEOUT tempo;
            al_init_timeout(&tempo, 0.01);
            bool temEventos = al_wait_for_event_until(filaEventos, &evento, 
                    &tempo);
            if(temEventos && ALLEGRO_EVENT_DISPLAY_CLOSE) {
                break;
            }
            
            ALLEGRO_BITMAP *imagem = al_load_bitmap("resources/images/bub.jpg"
                    );
            al_draw_bitmap(imagem, 0, 0, 0);
            al_flip_display();
        }
    }

    void MainView::inicializaSom() {
        if (!al_install_audio()) {
            cerr << "Falha ao inicializar áudio." << endl;
        }
 
        if (!al_init_acodec_addon()) {
            cerr << "Falha ao inicializar codecs de áudio." << endl;
        }

        if (!al_reserve_samples(canaisAudio)) {
            cerr << "Falha ao alocar canais de áudio." << endl;
        }

        al_attach_audio_stream_to_mixer(musica, al_get_default_mixer());
        al_set_audio_stream_playing(musica, true);
        musica = al_load_audio_stream(musicaArq.c_str(), 4, 1024);
    }

    void MainView::inicializaTeclado() {
        if (!al_install_keyboard()) {
            cerr << "Falha ao inicializar teclado." << endl;
        }
    }

    void MainView::setMusica(const std::string &musicaArq) {
        this->musicaArq = musicaArq;
        musica = al_load_audio_stream(musicaArq.c_str(), 4, 1024);
        if(musica == NULL) {
            cerr << "Erro ao carregar musica " << musicaArq << "." 
                << endl;
        }
    }

    void MainView::setTitulo(const std::string &titulo) {
        this->titulo = titulo;
        al_set_window_title(janela, titulo.c_str());
    }

    void MainView::inicializaImagem() {
        if(!al_init_image_addon()) {
           cerr << "Falha na inicialização do Allegro Image Addon" << endl;
        }
    }

    void MainView::setImagem(const std::string &imagemArq) {
        this->imagemArq = imagemArq;
        imagem = al_load_bitmap(imagemArq.c_str());        
    }

    void MainView::displayImagem(double x, double y, int flag) {
        al_draw_bitmap(imagem, x, y, flag);
        al_flip_display();
    }
}}
