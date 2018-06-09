/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */

#include "JogoView.h"
#include "ZoomIn.h"

bolhas::gui::JogoView::JogoView() : BaseView(), main(MainView::getInstance()),
    xFundo(main->getLargura()), xSource(400){
    controller = std::unique_ptr<JogoController> (new JogoController());
    fonte = std::unique_ptr<model::Fonts> (new model::Fonts(
        "../resources/fonts/smx.ttf", 85));
    numbers = std::unique_ptr<model::Fonts> (new model::Fonts(
        "../resources/fonts/agentred.ttf", 120));
    ingame = InGame::DISPLAYING;
    //fundoDeTela("../resources/images/under0.jpg");
    BaseView::fundoDeTela("../resources/images/under0.jpg");
    setMusica("../resources/sons/stratosphere.wav");
    playSom();
}

bolhas::gui::JogoView::~JogoView() {

}

void bolhas::gui::JogoView::renderizar(int x, int y) {
    model::Color cor(model::Colors::BRANCO);

    switch(ingame) {
        case InGame::DISPLAYING:
            BaseView::fundoDeTela();
            al_draw_text(fonte->getPointer(), cor.getCor(),
                (float) main->getLargura() / 2, (float) main->getAltura()
                / 2 - 170, ALLEGRO_ALIGN_CENTER, "COMECANDO EM:");
            if(!contagem()) {
                ingame = InGame::JOGANDO;
            }
            break;
        case InGame::JOGANDO:
            fundoDeTela("../resources/images/undermov.jpg");
        default:
            break;
    }

}


void bolhas::gui::JogoView::fundoDeTela() {
    xFundo += 3 * mult;
    xSource += 3 * mult;
    if(xFundo >= 5480 || xSource <= 400) {
        mult *= -1;
    }

    if(getFundo() != nullptr) {
        al_draw_bitmap_region(getFundo(), xSource, 0, xFundo,
            main->getAltura(), 0, 0, 0);
    }
}

void bolhas::gui::JogoView::fundoDeTela(const char *nome) {
    BaseView::fundoDeTela(nome);
}

bool bolhas::gui::JogoView::contagem() {
    if(efeitoFonte == nullptr) {
        using namespace animation;
        using model::Colors;
        efeitoFonte = std::unique_ptr<EfeitoFonte>
            (static_cast<EfeitoFonte *>((new ZoomIn(numbers.get(),
                Colors::BRANCO, Colors::VERMELHO, 180,
                numbers->getTamanho()))));
    }

    if(!efeitoFonte->animacao()) {
        if(texto.compare("3") == 0) {
            efeitoFonte->parar();
            texto = "2";
        } else if(texto.compare("2") == 0) {
            efeitoFonte->parar();
            texto = "1";
        } else {
            efeitoFonte->parar();
            texto = "3";
            return false;
        }
    }
    animation::ZoomIn *z = static_cast<animation::ZoomIn*>(efeitoFonte.get());
    al_draw_text(numbers->getPointer(), z->getCor().getCor(),
        (float) main->getLargura() / 2, (float) main->getAltura()
        / 2, ALLEGRO_ALIGN_CENTER, texto.c_str());
    return true;
}

