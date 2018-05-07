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
    class MainController {
        const MainView &view;
    public:
        MainController(const MainView &view);
        virtual ~MainController();
    private:

    };
}}

#endif /* MAINCONTROLLER_H */

