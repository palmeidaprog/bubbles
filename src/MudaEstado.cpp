/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */

#include "MudaEstado.h"
#include "MainView.h"

void bolhas::interfaces::MudaEstado::click(int x, int y) const {
    gui::MainView::getInstance()->setEstado(estado);

}

bolhas::interfaces::MudaEstado::MudaEstado(bolhas::Estado estado) :
        estado(estado) {}
