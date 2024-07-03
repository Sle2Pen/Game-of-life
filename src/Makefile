CC = cc
CFLAFS = -Wall -Werror -Wextra -std=c11
SOURCES = game_of_life.c game.c game.h renderer.c renderer.h file_loader.c file_loader.h buffers.c buffers.h termainal_settings.c terminal_settings.h
EXECUTABLE= ../build/game_of_life

all: style $(EXECUTABLE)

$(EXECUTABLE): game_of_life.o game.o renderer.o file_loader.o buffers.o terminal_settings.o
	$(CC) game_of_life.o game.o renderer.o file_loader.o buffers.o terminal_settings.o -o $(EXECUTABLE)

game_of_life.o: game_of_life.c game.h renderer.h file_loader.h buffers.h terminal_settings.h
	$(CC) $(CFLAGS) -c game_of_life.c

game.o: game.h game.c
	$(CC) $(CFLAGS) -c game.c

renderer.o: renderer.h renderer.c
	$(CC) $(CFLAGS) -c renderer.c

file_loader.o: file_loader.h file_loader.c
	$(CC) $(CFLAGS) -c file_loader.c

buffers.o: buffers.h buffers.c
	$(CC) $(CFLAGS) -c buffers.c

terminal_settings.o: terminal_settings.h terminal_settings.c
	$(CC) $(CFLAGS) -c terminal_settings.c

style:
	cp -R ../materials/linters/.clang-format ../src/.clang-format
	cp -R game.menu ../build/game.menu
	#clang-format -n *.c *.h

clean:
	rm -f *.o $(EXECUTABLE)
