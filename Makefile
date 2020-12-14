all: tet clear

tet: build/main.o build/foo.o 
	g++ build/main.o build/foo.o -o tet 
build/main.o: src/main.cpp
	g++ -Wall -Werror -o build/main.o -c src/main.cpp
build/foo.o: src/foo.cpp
	g++ -Wall -Werror -o build/foo.o -c src/foo.cpp  
clear:
	clear
clean:
	rm -rf build/* tet 
	clear
