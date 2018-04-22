
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <iostream>

using std::cerr;
using std::endl;

int main(int argc, char** argv) {
    ALLEGRO_DISPLAY *janela = NULL;
    
    if(!al_init()) {
        cerr << "Falha na inicialização do Allegro" << endl;
        return -1;
    }
    
    janela = al_create_display(1280,720);
    if(janela == NULL) {
        cerr << "Falha na criação da janela" << endl;
        return -1;
    }
    
    al_clear_to_color(al_map_rgb(0, 0, 0));  // preenche tela com cor
    al_flip_display(); // atualiza tela
    al_rest(10.0); // espera 10 segundos na tela
    al_destroy_display(janela); // fecha janela

    return 0;
}

