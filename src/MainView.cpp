/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */

// mainV View

#include "MainView.h"
#include "Passagem.h"

using namespace bolhas;

namespace bolhas { namespace gui {
    std::shared_ptr<MainView> MainView::instance;

    MainView::MainView(int largura, int altura) : Janela(largura, altura),
            BaseView(),
            fonte(nullptr), filaEventos(NULL),
            stop(false),
            titulo("Algebra Bolheana"),
            imagemArq("../resources/images/under0.jpg"), controller(nullptr),
            menu(nullptr), estadoMudado(false) {
        MainView::MainView::instance = std::shared_ptr<MainView> (this);
        estado = Estado::MENU;
        controller = new MainController(*this);
        scoreTime = std::shared_ptr<model::ScoreTime> (new model::ScoreTime(
            dificuldade));
        
        setTitulo(titulo);
        inicializaSom();
        playSom();
        inicializaEventos();
        inicializaFont();
        fonte = new model::Fonts("../resources/fonts/bubblegums.ttf", 72, true);
        inicializaImagem();
        inicializaMouse();
        inicializaTeclado();
        fundoDeTela("../resources/images/unders.jpg");
        fundoDeTela();
        al_flip_display();
    }

    MainView::~MainView() {
        delete menu;
        delete controller;

        al_destroy_event_queue(filaEventos);
    }

    void MainView::inicializaEventos() {
        filaEventos = al_create_event_queue();
        
        if(filaEventos == NULL) {
            //throw excecoes::JanelaException("Erro ao criaar eventos.");
            cerr << "Erro ao criar eventos" << endl;
        }

        al_register_event_source(filaEventos, al_get_display_event_source(
                Janela::getJanela()));


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

        setMusica("../resources/sons/Space_Loop.wav");
        setEfeito("../resources/sons/load.wav");

        //getSample() = al_load_sample(getMusica().c_str());


        //al_attach_audio_stream_to_mixer(musica, al_get_default_mixer());
        //al_set_audio_stream_playing(musica, true);
        //musica = al_load_audio_stream(musicaArq.c_str(), 4, 1024);
    }

    void MainView::inicializaTeclado() {
        if (!al_install_keyboard()) {
            cerr << "Falha ao inicializar teclado." << endl;
        }
        al_register_event_source(filaEventos, al_get_keyboard_event_source());
    }



    void MainView::inicializaFont() {
        al_init_font_addon();
        if(!al_init_ttf_addon()) {
            cerr << "Falha ao inicializar addon de TTF." << endl;
        }
    }

    void MainView::setTitulo(const std::string &titulo) {
        this->titulo = titulo;
        al_set_window_title(Janela::getJanela(), titulo.c_str());
    }

    void MainView::inicializaImagem() const {
        if(!al_init_image_addon()) {
           cerr << "Falha na inicialização do Allegro Image Addon" << endl;
        }
    }


    ALLEGRO_EVENT_QUEUE *MainView::getEventos() const {
        return filaEventos;
    }


    void MainView::escondeMenu() {
        delete menu;
        menu = NULL;
    }

    void MainView::renderizaTela(int x, int y) {
        switch(estado) {
            case Estado::JOGO:
                if(estadoMudado) {
                    estadoMudado = false;
                    transition.reset(static_cast<animation::Transition *>(
                        new animation::Passagem(new model::Color
                        (model::Colors::PRETO), getLargura(), getAltura())));
                    estado = Estado::TRANSICAO;
                    stopSom();
                    playEfeito();
                } else {
                    if(!jogo) {
                        jogo = std::unique_ptr<JogoView> (new JogoView());
                    } else {
                        jogo->renderizar(x, y);
                    }
                }
                break;
            case Estado::TRANSICAO:
                fundoDeTela();
                mostraMenu(x, y);
                if(!transition->animar()) {
                    fundoDeTela("../resources/images/under0.jpg");
                    model::Color cor(model::Colors::PRETO);
                    al_clear_to_color(cor.getCor());
                    estado = Estado::TRANSICAO_REV;
                    transition.reset(static_cast<animation::Transition *>(
                        new animation::Passagem(new model::Color
                        (model::Colors::PRETO), getLargura(), getAltura(),
                            true)));
                }
                break;
            case Estado::TRANSICAO_REV:
                fundoDeTela();
                if(!transition->animar()) {
                    fundoDeTela();
                    estado = Estado::JOGO;
                }
                break;
            case Estado::MENU:
                fundoDeTela();
                mostraMenu(x, y);
                break;
            case Estado::SAIR:
                break;
            default:
                break;
        }
    }

    void MainView::mostraMenu(int x, int y) {

        if(menu == nullptr) {
            menu = new MenuView(*this, x, y);
        } else {
            menu->renderiza(x, y);
        }
    }

    // Copia da fonte
    model::Fonts MainView::getFonte() const {
        return *fonte;
    }

    void MainView::inicializaMouse() {
        if(!al_install_mouse()) {
            cerr << "Nao foi possível iniciar mouse addon." << endl;
        }
        al_register_event_source(filaEventos, al_get_mouse_event_source());
        //al_hide_mouse_cursor(getJanela());
    }

    bool MainView::click(int x, int y) {
        switch(estado) {
            case Estado::MENU:
                return menu->click(x, y);
            case Estado::JOGO:
                return jogo->click(x, y);
            default:
                return false;
        }
    }

    model::DificuldadeJogo MainView::getDificuldade() const {
        return dificuldade;
    }

    void MainView::setDificuldade(model::DificuldadeJogo dificuldade) {
        MainView::dificuldade = dificuldade;
    }

}}
