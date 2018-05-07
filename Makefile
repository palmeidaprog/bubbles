TARGET = bin/bubbles
CC = g++
CPPFLAGS = -g -std=c++14 -Wall 
LDFLAGS = -lm -lallegro -lallegro_main -lallegro_image -lallegro_audio -lallegro_acodec
OBJECTS = main.o MainView.o MainController.o JanelaException.o
EXEC = bin/bubbles

SRC = src/main.c src/gui/MainView.cpp sec/excecoes/JanelaException.cpp

$(TARGET): $(OBJECTS)
	$(CC) $(LIBS) -o $(TARGET) $(OBJECTS)

main.o :
	$(CC) $(CPPFLAFS) -c /src/main.cpp

MainView.o: /src/gui/MainView.h
	$(CC) $(CPPFLAFS) -c /src/gui/MainView.cpp

MainController.o: /src/gui/MainController.h
	$(CC) $(CPPFLAFS) -c /src/gui/MainController.cpp

JanelaException.o: /src/gui/JanelaException.h
	$(CC) $(CPPFLAFS) -c /src/gui/JanelaException.cpp


clean: 
	-rm -f *.o
	-rm -f $(TARGET)


