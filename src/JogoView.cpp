/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */

#include "JogoView.h"


bolhas::gui::JogoView::JogoView() : BaseView(), mainV(MainView::getInstance()),
    xFundo(mainV->getLargura()), xSource(400), texto("3"), cor(0.1), cor2(1), 
	trans(0.2), mult(1) {
    score = std::shared_ptr<model::ScoreTime> (
        model::ScoreTime::getInstance());
    controller = std::unique_ptr<JogoController> (new JogoController(this));
    fonte = std::unique_ptr<model::Fonts> (new model::Fonts(
        "resources/fonts/smx.ttf", 85));
    numbers = std::unique_ptr<model::Fonts> (new model::Fonts(
        "resources/fonts/agentred.ttf", 30));
    ingame = InGame::DISPLAYING;
    dados = std::unique_ptr<EntradaDados> (new EntradaDados());
    //fundoDeTela("resources/images/under0.jpg");
    BaseView::fundoDeTela("resources/images/under0.jpg");
    setMusica("resources/sons/stratosphere.wav");
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
                (float) mainV->getLargura() / 2, (float) mainV->getAltura()
                / 2 - 250, ALLEGRO_ALIGN_CENTER, "COMECANDO EM:");
            if(!contagem()) {
                ingame = InGame::JOGANDO;
                fundoDeTela("resources/images/undermov.jpg");
                controller->adicionaBolha();
                //dados->mostraBalao(true);
            }
            break;
        case InGame::JOGANDO:
            if(model::ScoreTime::getInstance()->timeOver()) {
                char msg[25];
				#if defined(WIN32) || defined(_WIN32)
                _snprintf_s(msg, 25, _TRUNCATE, "Seus pontos: %d",
					model::ScoreTime::getInstance()->getScore());
				#else
				snprintf(msg, 25, "Seus pontos: %d",
					model::ScoreTime::getInstance()->getScore());
				#endif
                al_show_native_message_box(
                    MainView::getInstance()->getJanela(),"Score", "GAME OVER",
                    msg, "Ok", ALLEGRO_MESSAGEBOX_WARN);
                ingame = InGame::DISPLAYING;
                MainView::getInstance()->setEstado(Estado::MENU);
                return;
            }
            fundoDeTela();
            cabecalho(x, y);
            controller->renderizaBolhas(x, y);
            dados->renderiza(x, y);
            break;
        default:
            break;
    }
}


void bolhas::gui::JogoView::fundoDeTela() {
    xFundo += 2 * mult;
    xSource += 2 * mult;
    if(xFundo >= 5480 || xSource <= 400) {
        mult *= -1;
    }

    if(getFundo() != nullptr) {

        al_draw_bitmap_region(getFundo(), xSource, 0, xFundo,
            mainV->getAltura(), 0, 0, 0);
        //al_hold_bitmap_drawing(false);

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
                Colors::BRANCO, Colors::VERMELHO, 210,
                numbers->getTamanho()))));
    }

    if(!efeitoFonte->animacao()) {
        cor = 0.1;
        cor2 = 1;
        if(texto.compare("3") == 0) {
            efeitoFonte->parar();
            texto = "2";
        } else if(texto.compare("2") == 0) {
            efeitoFonte->parar();
            texto = "1";
        } else {
            efeitoFonte->parar();
            texto = "3";
            efeitoFonte.reset(nullptr);
            return false;
        }
    }
    cor += 0.01;
    cor2 -= 0.01;
    trans += 0.01;
    animation::ZoomIn *z = static_cast<animation::ZoomIn*>(efeitoFonte.get());
    al_draw_text(numbers->getPointer(), al_map_rgba_f(cor, cor2, cor2, trans),
        (float) mainV->getLargura() / 2, (float) mainV->getAltura()
        / 2 - 110, ALLEGRO_ALIGN_CENTER, texto.c_str());
    return true;
}

void bolhas::gui::JogoView::cabecalho(int x, int y) {
    if(painel == nullptr) {
        painel = std::unique_ptr<PainelSuperiorView>(new PainelSuperiorView(
            *numbers));

    }
    painel->renderizar(x, y);
}

bool bolhas::gui::JogoView::click(int x, int y) {
    return controller->click(x, y);
}

