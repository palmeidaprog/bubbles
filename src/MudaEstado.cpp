//
// Created by Paulo Roberto Almeida Filho on 6/8/18.
//

#include "MudaEstado.h"
#include "MainView.h"

void bolhas::interfaces::MudaEstado::click() const {
    using mv = gui::MainView;
    mv.getInstance().setEstado(estado);
}

bolhas::interfaces::MudaEstado::MudaEstado(bolhas::Estado estado) :
        estado(estado) {}
