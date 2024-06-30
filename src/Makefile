CC = cc
CFLAFS = -Wall -Werror -Wextra -std=c11
SOURCES = game_of_life.c game.c game.h renderer.c renderer.h buffers.c buffers.h
EXECUTABLE= ../build/game_of_life

all: style $(EXECUTABLE)

$(EXECUTABLE): game_of_life.o game.o renderer.o buffers.o
	$(CC) game_of_life.o game.o renderer.o buffers.o -o $(EXECUTABLE)

game_of_life.o: game_of_life.c game.h renderer.h buffers.h
	$(CC) $(CFLAGS) -c game_of_life.c

game.o: game.h game.c
	$(CC) $(CFLAGS) -c game.c

renderer.o: renderer.h renderer.c
	$(CC) $(CFLAGS) -c renderer.c

buffers.o: buffers.h buffers.c
	$(CC) $(CFLAGS) -c buffers.c

style:
	cp -R ../materials/linters/.clang-format ../src/.clang-format
	#clang-format -n *.c *.h

clean:
	rm -f *.o $(EXECUTABLE)
