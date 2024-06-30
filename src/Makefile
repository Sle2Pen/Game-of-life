CC = cc
CFLAFS = -Wall -Werror -Wextra -std=c11
SOURCES = game_of_life.c game.c game.h
EXECUTABLE= ../build/game_of_life

all: style $(EXECUTABLE)

$(EXECUTABLE): game_of_life.o game.o
	$(CC) game_of_life.o game.o -o $(EXECUTABLE)

game_of_life.o: game_of_life.c game.h
	$(CC) $(CFLAGS) -c game_of_life.c

game.o: game.h game.c
	$(CC) $(CFLAGS) -c game.c

style:
	cp -R ../materials/linters/.clang-format ../src/.clang-format
	#clang-format -n *.c *.h

clean:
	rm -f *.o $(EXECUTABLE)
