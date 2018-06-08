cmake_minimum_required(VERSION 3.10)
project(bubbles)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-L /usr/local/lib -lallegro -lallegro_main -lallegro_image -lallegro_audio -lallegro_acodec -lallegro_font -lallegro_ttf ")        #Allegro

include_directories(src)

add_executable(bubbles
        resources/fonts/ARCADECLASSIC.TTF
        resources/fonts/chalkduster.ttf
        resources/images/bubl.jpg
        resources/images/color.jpg
        resources/images/unders.jpg
        resources/sons/auxiliaresc.pdf
        "resources/sons/Fantasy Game Loop.wav"
        resources/sons/menu.mp3
        resources/sons/pop.mp3
        resources/sons/Space_Loop.wav
        "resources/sons/Star Commander1.wav"
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
        src/ZoomFont.h src/MenuItem.cpp src/MenuItem.h src/Observado.cpp src/Observado.h src/Observador.cpp src/Observador.h src/Evento.h src/EfeitoFonte.cpp src/EfeitoFonte.h)

