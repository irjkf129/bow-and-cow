all: bin/bow format

bin/bow: build/src/main.o 
	gcc -Wall -Werror build/src/main.o -o bin/bow

build/src/main.o: src/main.c
	gcc -Wall -Werror -c src/main.c -o build/src/main.o

clear:
	rm -rf build/src/*.o build/test/*.o bin/bow

format:
	clang-format -i src/main.c