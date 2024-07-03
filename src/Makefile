CC = cc
CFLAFS = -Wall -Werror -Wextra -std=c11
#SOURCES = game_of_life.c game.c game.h renderer.c renderer.h termainal_settings.c terminal_settings.h file_unit.c file_unit.h buffers.c buffers.h
SOURCES = game_of_life.c game.c game.h renderer.c renderer.h termainal_settings.c terminal_settings.h buffers.c buffers.h
EXECUTABLE= ../build/game_of_life

all: style $(EXECUTABLE)

#$(EXECUTABLE): game_of_life.o game.o renderer.o terminal_settings.o file_unit.o buffers.o
#	$(CC) game_of_life.o game.o renderer.o terminal_settings.o file_unit.o buffers.o -o $(EXECUTABLE)
$(EXECUTABLE): game_of_life.o game.o renderer.o terminal_settings.o buffers.o
	$(CC) game_of_life.o game.o renderer.o terminal_settings.o buffers.o -o $(EXECUTABLE)

#game_of_life.o: game_of_life.c game.h renderer.h terminal_settings.h file_unit.h buffers.h
game_of_life.o: game_of_life.c game.h renderer.h buffers.h terminal_settings.h
	$(CC) $(CFLAGS) -c game_of_life.c

game.o: game.h game.c
	$(CC) $(CFLAGS) -c game.c

renderer.o: renderer.h renderer.c
	$(CC) $(CFLAGS) -c renderer.c

#file_unit.o: file_unit.h file_unit.c
#	$(CC) $(CFLAGS) -c file_unit.c

buffers.o: buffers.h buffers.c
	$(CC) $(CFLAGS) -c buffers.c

terminal_settings.o: terminal_settings.h terminal_settings.c
	$(CC) $(CFLAGS) -c terminal_settings.c

style:
	cp -R ../materials/linters/.clang-format ../src/.clang-format
	#clang-format -n *.c *.h

clean:
	rm -f *.o $(EXECUTABLE)
