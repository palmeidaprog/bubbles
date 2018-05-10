TARGET = bin/bubbles
CC = g++
CPPFLAGS = -g -std=c++14 -Wall 
LDFLAGS = -lm -lallegro -lallegro_main -lallegro_image -lallegro_audio -lallegro_acodec
OBJECTS = build/main.o build/MainView.o build/MainController.o build/JanelaException.o


$(TARGET): $(OBJECTS)
	$(CC) $(LIBS) -o $(TARGET) $(OBJECTS)

build/main.o : src/main.cpp
	$(CC) $(CPPFLAFS) -c src/main.cpp

build/MainView.o: src/gui/MainView.h src/gui/MainView.cpp
	$(CC) $(CPPFLAFS) -c src/gui/MainView.cpp

build/MainController.o: src/gui/MainController.h src/gui/MainController.cpp
	$(CC) $(CPPFLAFS) -c src/gui/MainController.cpp

build/JanelaException.o: src/gui/JanelaException.h src/gui/JanelaException.cpp
	$(CC) $(CPPFLAFS) -c src/gui/JanelaException.cpp

clean: 
	-rm -f *.o
	-rm -f $(TARGET)


