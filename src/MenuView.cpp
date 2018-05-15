/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */

#include "MenuView.h"

// construtor
namespace bolhas { namespace gui {
    MenuView::MenuView(ALLEGRO_FONT *fonte_, const int altura, const int 
            largura) : fonte(fonte_), ALTURA(altura), LARGURA(largura) {
        criarMenu();
    }

    void MenuView::criarMenu() const {

        //al_draw_text(fonte, al_map_rgb(0, 0, 0), 10, 10, ALLEGRO_ALIGN_LEFT, "Esquerda");
        // Texto alinhado à direita
        al_draw_text(fonte, al_map_rgb(0, 255, 0), LARGURA - 10, 50, ALLEGRO_ALIGN_RIGHT, "Direita");
        // Texto centralizado
        al_draw_text(fonte, al_map_rgb(0, 0, 255), LARGURA / 2, 90, ALLEGRO_ALIGN_CENTRE, "Centro");
    
        // Exemplo de impressão de valores variáveis
        int i = 2;
        
        al_draw_textf(fonte, al_map_rgb(0, 0, 0), LARGURA / 2, 250, ALLEGRO_ALIGN_CENTRE, "Teste %d - %s", i, "Uma str");
    }
}}