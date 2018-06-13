/*
 * UNICAP - Universidade Catolica de Pernambuco
 * Pratica de Programação
 * Prof: Me. Ana Eliza Moura
 * Projeto 02 - Algebra Bolheana
 * Aluno: Paulo R. Almeida Filho
 * E-mail: pauloalmeidaf@gmail.com
 */

#include "BolhaGui.h"
#include "MainView.h"

bolhas::model::BolhaGui::BolhaGui(bolhas::model::BolhasController *controller,
            int posX, int posY, AcaoBolha acao) : posX(posX), posY(posY), 
			tamanho(1), spriteNum(1), animate(false), scale(0.4) {
    this->acao = acao;

    // movemimento aleatorio
    moveX = (rand() % 3) - 1;
    moveY = (rand() % 3) - 1;

    this->controller = std::shared_ptr<model::BolhasController> (controller);
    data = std::unique_ptr<model::Bolha> (new model::Bolha(
        controller->getDificuldade()));
    delay = std::unique_ptr<model::Delay> (new model::Delay(0.1));
    explode = std::unique_ptr<model::Delay> (new model::Delay(0.25));
    seca = std::unique_ptr<model::Delay> (new model::Delay(0.25));
    fonte = std::unique_ptr<model::Fonts> (new model::Fonts(
        controller->getFonte().get()));
    tempoDeVida = std::unique_ptr<model::Delay> (new model::Delay(
        data->tempoDeVida()));
    anima = std::unique_ptr<model::Delay> (new model::Delay(0.15));
    cor = std::unique_ptr<model::Color> (new model::Color(
        model::Colors::BRANCO_FUMACA));
}

void bolhas::model::BolhaGui::renderizar(int x, int y) {
    using model::Colors;
    imagem = controller->getBitmap(acao, spriteNum);

    if(acao == AcaoBolha::SECANDO) {
        animacaoSecando();
    } else if(acao == AcaoBolha::EXPLODINDO) {
        animacaoExplodindo();
    }

    checarLimites();
    if(tempoDeVida->ready()) {
        acao = AcaoBolha::SECANDO;
        animate = false;
        cor->setColor(Colors::BRANCO_FUMACA);
        return ;
    } else if(tempoDeVida->isClose()) {
        animate = true;
    }

    if(acao == AcaoBolha::DESTRUIDA) {
        return;
    }

    if(this == controller->getSelected() &&
       gui::EntradaDados::getInstance()->isEnter()) {
        int r = gui::EntradaDados::getInstance()->getResp();
        /*try {
            r = std::stoi(gui::EntradaDados::getInstance()->getResp());
        } catch(const std::invalid_argument &e) {
            // fazer nada
        }
*/
       if(data->verificaResposta(r)) {
           ScoreTime::getInstance()->bolhaCerta();
           acao = AcaoBolha::EXPLODINDO;
           animate = false;
           cor->setColor(Colors::BRANCO_FUMACA);
           return;
       } else {
           ScoreTime::getInstance()->bolhaErrada();
       }
    }


    if(delay->ready()) {
        scale *= 1.01;
        posX += 5 * moveX;
        posY += 5 * moveY;
        int tam = fonte->getTamanho();
        fonte->setTamanho(static_cast<int>(fonte->getTamanho() * 1.01));
    }

    float w = al_get_bitmap_width(imagem);
    float h = al_get_bitmap_height(imagem);

    al_draw_tinted_scaled_bitmap(imagem, cor->getCor(), 0, 0, w, h, posX, posY,
        w * scale, h * scale, 0);
    if(controller->getSelected() != this && animate && anima->ready() &&
            acao == AcaoBolha::NORMAL) {
        if(anima->getDelay() > 0.05) {
            anima->setDelay(anima->getDelay() * 0.9);
        }

        if(cor->getColor() != Colors::BRANCO_FUMACA) {
            cor->setColor(Colors::BRANCO_FUMACA);
        } else {
            cor->setColor(Colors::LARANJA_ACESO);
        }

    } else if(controller->getSelected() != this && !animate) {
        cor->setColor(Colors::BRANCO_FUMACA);
    }


    if(acao == AcaoBolha::NORMAL) {
        model::Color corTexto(model::Colors::BRANCO_FUMACA);

        al_draw_text(controller->getFonte()->getPointer(), corTexto.getCor(),
            posX + (w * scale / 2), posY + (h * scale * 0.43),
            ALLEGRO_ALIGN_CENTER, data->expressao().c_str());
    }
}

bolhas::model::BolhaGui::~BolhaGui() {

}

void bolhas::model::BolhaGui::checarLimites() {
    if (posY + al_get_bitmap_height(imagem) * scale >=
        gui::MainView::getInstance()->getAltura()) {
        moveY = -1;
    } else if (posY <= 0) {
        moveY = 1;
    }

    if (posX + al_get_bitmap_width(imagem) * scale >=
        gui::MainView::getInstance()->getLargura()) {
        moveX = -1;
    } else if (posX <= 0) {
        moveX = 1;
    }
}

void bolhas::model::BolhaGui::animacaoSecando() {
    if(seca->ready()) {
        spriteNum += 1;
    }


    if(!controller->validaSpriteNum(acao, spriteNum)) {
        acao = AcaoBolha::DESTRUIDA;
        ScoreTime::getInstance()->bolhaEstourada();
        return;
    }
    float w = al_get_bitmap_width(imagem);
    float h = al_get_bitmap_height(imagem);

    al_draw_tinted_scaled_bitmap(imagem, cor->getCor(), 0, 0, w, h, posX, posY,
        w * scale, h * scale, 0);


}

void bolhas::model::BolhaGui::animacaoExplodindo() {
    if(explode->ready()) {
        spriteNum += 1;
        if (spriteNum == 4) {
			//gui::MainView::getInstance()->playPop();
        }
    }
    std::cout << "acertou" << std::endl;

    if(!controller->validaSpriteNum(acao, spriteNum)) {
        acao = AcaoBolha::DESTRUIDA;
        ScoreTime::getInstance()->bolhaCerta();
        return;
    }
    float w = al_get_bitmap_width(imagem);
    float h = al_get_bitmap_height(imagem);

    al_draw_tinted_scaled_bitmap(imagem, cor->getCor(), 0, 0, w, h, posX, posY,
        w * scale, h * scale, 0);
}

bolhas::model::AcaoBolha bolhas::model::BolhaGui::getAcao() const {
    return acao;
}

bool bolhas::model::BolhaGui::click(int x, int y) {
    if(x >= posX && x <= posX + al_get_bitmap_width(imagem) * scale &&
       y >= posY && y <= posY + al_get_bitmap_height(imagem) * scale) {
        cor->setColor(model::Colors::VERMELHO);
        controller->setSelected(this);
        gui::EntradaDados::getInstance()->setTexto(data->expressao());
        gui::EntradaDados::getInstance()->mostraBalao(true);
        return true;
    }
    return false;
}

bolhas::model::Bolha *bolhas::model::BolhaGui::getData() {
    return data.get();
}


