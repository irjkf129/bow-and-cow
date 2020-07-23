all: bin/bow format

bin/bow: build/src/main.o build/src/game.o
	gcc -Wall -Werror build/src/main.o build/src/game.o -o bin/bow

build/src/main.o: src/main.c src/game.h
	gcc -Wall -Werror -c src/main.c -o build/src/main.o

build/src/game.o: src/game.c src/game.h
	gcc -Wall -Werror -c src/game.c -o build/src/game.o

clear:
	rm -rf build/src/*.o build/test/*.o bin/bow

format:
	clang-format -i src/main.c