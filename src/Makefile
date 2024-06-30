CC = cc
CFLAFS = -Wall -Werror -Wextra
SOURCES= game_of_life.c game.c game.h
EXECUTABLE= ../build/game_of_life

all: style game_of_life

style:
	cp -R ../materials/linters/.clang-format ../src/.clang-format
	#clang-format -n *.c *.h

game_of_life:
	$(CC) $(CFLAGS) $(SOURCES) -o $(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE)
