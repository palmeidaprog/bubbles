cmake_minimum_required(VERSION 3.10)
project(bubbles)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-g -lm -lallegro -lallegro_main -lallegro_image -lallegro_audio -lallegro_acodec -lallegro_font -lallegro_ttf ")        #Allegro

include_directories(src)

# FILE(TO_NATIVE_PATH "${CMAKE_SOURCE_DIR}/resources" source)
add_custom_command(TARGET bubbles PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/config $<TARGET_FILE_DIR:resources>)

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
        src/MenuView.h)

