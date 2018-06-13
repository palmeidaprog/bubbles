/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */

#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include "MainView.h"

namespace bolhas { namespace gui {
    class MainView;
    class MainController {
        const gui::MainView &view;
        
    public:
        MainController(const gui::MainView &view_);
        virtual ~MainController();

    };
}}

#endif /* MAINCONTROLLER_H */

