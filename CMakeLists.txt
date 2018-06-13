cmake_minimum_required(VERSION 3.10)
project(bubbles)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-L /usr/local/lib -lallegro -lallegro_dialog -lallegro_main -lallegro_image -lallegro_audio -lallegro_acodec -lallegro_font -lallegro_ttf ")        #Allegro

include_directories(src)

add_executable(bubbles
        src/../resources/fonts/ARCADECLASSIC.TTF
        src/../resources/fonts/chalkduster.ttf
        src/../resources/images/bubl.jpg
        src/../resources/images/color.jpg
        src/../resources/images/unders.jpg
        "src/../resources/sons/Fantasy Game Loop.wav"
        src/../resources/sons/menu.mp3
        src/../resources/sons/pop.mp3
        src/../resources/sons/Space_Loop.wav
        "src/../resources/sons/Star Commander1.wav"
        src/Estado.h
        src/JanelaException.cpp
        src/JanelaException.h
        src/main.cpp
        src/MainController.cpp
        src/MainController.h
        src/MainView.cpp
        src/MainView.h
        src/MenuController.cpp
        src/MenuController.h
        src/MenuView.cpp
        src/MenuView.h
        src/Fonts.cpp
        src/Fonts.h
        src/Delay.cpp
        src/Delay.h
        src/Color.cpp
        src/Color.h
        src/Colors.h
        src/Janela.cpp
        src/Janela.h
        src/Memento.h
        src/ZoomFont.cpp
        src/ZoomFont.h src/MenuItem.cpp src/MenuItem.h src/Observado.cpp src/Observado.h src/Observador.cpp src/Observador.h src/EventoTipo.h src/EfeitoFonte.cpp src/EfeitoFonte.h src/Clickavel.h src/MudaEstado.cpp src/MudaEstado.h src/Transition.h src/Passagem.cpp src/Passagem.h src/JogoView.cpp src/JogoView.h src/JogoController.cpp src/JogoController.h src/BaseView.cpp src/BaseView.h src/ZoomIn.cpp src/ZoomIn.h src/PainelSuperiorView.cpp src/PainelSuperiorView.h src/Bolha.cpp src/Bolha.h src/BolhaTipo.h src/DificuldadeJogo.h src/BolhaGui.cpp src/BolhaGui.h src/BolhasController.cpp src/BolhasController.h src/AcaoBolha.cpp src/AcaoBolha.h src/ScoreTime.cpp src/ScoreTime.h src/EntradaDados.cpp src/EntradaDados.h)

