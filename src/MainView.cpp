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
            ALTURA(altura), fonte(NULL), janela(NULL), filaEventos(NULL),
            musica(NULL), sample(NULL), fundo(NULL), stop(false), tamanhoFonte(24), 
            musicaArq("resources/sons/Space_Loop.wav"), titulo(
                "Algebra Bolheana"), imagemArq(
                    "resources/images/bubl.jpg"), nomeFonte(
                        "resources/fonts/arcadeclassic.ttf", estado(Estado::MENU)) {
        
        controller = new MainController(*this);
        
        setTitulo(titulo);
        inicializaSom();
        playSom();
        inicializaTeclado();
        janela = al_create_display(LARGURA, ALTURA);
        if(janela == NULL) {
            throw excecoes::JanelaException("Erro ao abrir janela principal."
                    );
        }
        inicializaImagem();
        fundoDeTela("resources/images/unders.jpg");
        inicializaEventos();
        inicializaFont();
        mostraMenu();
    }

    MainView::~MainView() {
        al_destroy_audio_stream(musica);
        al_destroy_sample(sample);
        al_destroy_display(janela); // fecha janela
        al_destroy_event_queue(filaEventos);
    }

    void MainView::inicializaEventos() {
        filaEventos = al_create_event_queue();
        
        if(filaEventos == NULL) {
            throw excecoes::JanelaException("Erro ao criaar eventos.");        
        }

        al_register_event_source(filaEventos, al_get_display_event_source(janela));
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

        sample = al_load_sample(musicaArq.c_str());

        //al_attach_audio_stream_to_mixer(musica, al_get_default_mixer());
        //al_set_audio_stream_playing(musica, true);
        //musica = al_load_audio_stream(musicaArq.c_str(), 4, 1024);
    }

    void MainView::inicializaTeclado() {
        if (!al_install_keyboard()) {
            cerr << "Falha ao inicializar teclado." << endl;
        }
    }

    void MainView::setMusica(const std::string &musicaArq) {
        this->musicaArq = musicaArq;
        sample = al_load_sample(musicaArq.c_str());
        /*musica = al_load_audio_stream(musicaArq.c_str(), 4, 1024);
        if(musica == NULL) {
            cerr << "Erro ao carregar musica " << musicaArq << "." 
                << endl;
        }*/
    }

    void MainView::inicializaFont() {
        if(!al_init_ttf_addon()) {
            cerr << "Falha ao inicializar addon de TTF." << endl;
        }
        mudaFonte(nomeFonte.c_str(), tamanhoFonte); 
    }

    void MainView::setTitulo(const std::string &titulo) {
        this->titulo = titulo;
        al_set_window_title(janela, titulo.c_str());
    }

    void MainView::inicializaImagem() const {
        if(!al_init_image_addon()) {
           cerr << "Falha na inicialização do Allegro Image Addon" << endl;
        }
    }

    void MainView::setImagem(const std::string &imagemArq) {
        this->imagemArq = imagemArq;
        fundo = al_load_bitmap(imagemArq.c_str());        
    }

    void MainView::playSom() const {
        al_play_sample(sample, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,NULL);
    }

    ALLEGRO_EVENT_QUEUE *MainView::getEventos() const {
        return filaEventos;
    }

    void MainView::fundoDeTela(const char *nome) {
        fundo = al_load_bitmap(nome);
        if(fundo != NULL) {
            fundoDeTela();
        }        
    }

    void MainView::fundoDeTela() const {
        al_draw_bitmap(fundo, 0, 0, 0);
        al_flip_display();
    }

    void MainView::mudaFonte(const std::string &nome, int tamanhoFonte) {
        nomeFonte = nome;
        this->tamanhoFonte = tamanhoFonte;
        fonte = al_load_ttf_font(nome.c_str(), tamanhoFonte, 0);
    }

    void MainView::mudaFonte(const std::string &nome) {
        mudaFonte(nome, tamanhoFonte);
    }

    void MainView::escondeMenu() {
        delete menu;
        menu = NULL;
    }
}}
