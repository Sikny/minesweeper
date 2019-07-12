CC=g++
CFLAGS=-Wall -std=c++11
EXEC_NAME=Minesweeper.exe
INCLUDES=-IC:\Users\pamar\Documents\Libs\SFML-2.5.1\include
LIBS=-LC:\Users\pamar\Documents\Libs\SFML-2.5.1\lib -lsfml-graphics -lsfml-window -lsfml-system
OBJ_FILES=main.o game.o case.o
INSTALL_DIR=build

all: $(EXEC_NAME) install clean run

clean:
	del $(EXEC_NAME) $(OBJ_FILES)

$(EXEC_NAME): $(OBJ_FILES)
	$(CC) -o $(EXEC_NAME) $(OBJ_FILES) $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

%.o: %.cc
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

%.o: %.c
	gcc $(CFLAGS) $(INCLUDES) -o $@ -c $<

install:
	copy $(EXEC_NAME) $(INSTALL_DIR)

run:
	$(INSTALL_DIR)/$(EXEC_NAME)