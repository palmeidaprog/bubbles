/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */

#include "gui/MainView.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <iostream>

using std::cerr;
using std::endl;
using namespace bolhas;

int main(int argc, char** argv) {
    ALLEGRO_BITMAP *imagem = NULL;
    
    if(!al_init()) {
        cerr << "Falha na inicialização do Allegro" << endl;
        return -1;
    }
    
    if(!al_init_image_addon()) {
        cerr << "Falha na inicialização do Allegro Image Addon" << endl;
    }
    
    try {
        gui::MainView *janela = new gui::MainView(1280, 720);
    } catch(const excecoes::JanelaException &e) {
        cerr << e.what() << endl;
        return -1;
    }
    
    
    imagem = al_load_bitmap("resources/images/color.jpg");
    al_draw_bitmap(imagem, 0, 0, 0);
    //al_clear_to_color(al_map_rgb(0, 0, 0));  // preenche tela com cor
    al_flip_display(); // atualiza tela
    al_rest(10.0); // espera 10 segundos na tela
    

    return 0;
}

