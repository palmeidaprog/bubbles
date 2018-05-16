TARGET = bin/bubbles
CC = g++
CPPFLAGS = -g -std=c++14 -Wall 

LIBS = -lm -lallegro -lallegro_main -lallegro_image -lallegro_audio -lallegro_acodec -lallegro_font -lallegro_ttf
OBJECTS = build/main.o build/MainView.o build/MainController.o build/JanelaException.o build/MenuView.o
EXEC = bin/bubbles

$(TARGET): $(OBJECTS)
	$(CC) $(LIBS) -o $(TARGET) $(OBJECTS)

build/main.o: src/main.cpp
	$(CC) $(CPPFLAGS) -c src/main.cpp -o build/main.o

build/MainView.o: src/MainView.cpp src/MainView.h
	$(CC) $(CPPFLAGS) -c src/MainView.cpp -o build/MainView.o

build/MainController.o: src/MainController.cpp src/MainController.h
	$(CC) $(CPPFLAGS) -c src/MainController.cpp -o build/MainController.o

build/JanelaException.o: src/JanelaException.cpp src/JanelaException.h
	$(CC) $(CPPFLAGS) -c src/JanelaException.cpp -o build/JanelaException.o

build/MenuView.o: src/MenuView.cpp src/MenuView.h
	$(CC) $(CPPFLAGS) -c src/MenuView.cpp -o build/MenuView.o

clean: 
	-rm -f build/*.o
	-rm -f $(TARGET)


