all: bin/bow bin/game_test format

bin/bow: build/src/main.o build/src/game.o
	gcc -Wall -Werror build/src/main.o build/src/game.o -o bin/bow

build/src/main.o: src/main.c src/game.h
	gcc -Wall -Werror -c src/main.c -o build/src/main.o

build/src/game.o: src/game.c src/game.h
	gcc -Wall -Werror -c src/game.c -o build/src/game.o

bin/game_test: build/src/game.o build/test/main.o build/test/game_test.o
	gcc -Wall -Werror build/src/game.o build/test/main.o build/test/game_test.o -o bin/game_test

build/test/main.o: thirdparty/ctest.h test/main.c
	gcc -I thirdparty -c test/main.c -o build/test/main.o

build/test/game_test.o: test/game_test.c thirdparty/ctest.h src/game.h
	gcc -I thirdparty -I src -c test/game_test.c -o build/test/game_test.o

clear:
	rm -rf build/src/*.o build/test/*.o bin/bow bin/game_test

format:
	clang-format -i src/main.c