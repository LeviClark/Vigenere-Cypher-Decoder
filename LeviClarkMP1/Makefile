MiniProject1: Main.o Cipher.o
	g++ -std=c++11 -g -Wall Cipher.o Main.o -o MiniProject1

Main.o: Cipher.h Main.cpp
	g++ -std=c++11 -g -Wall -c Main.cpp

Cipher.o: Cipher.h Cipher.cpp
	g++ -std=c++11 -g -Wall -c Cipher.cpp

test: MiniProject1 Main.cpp
	./MiniProject1

clean:
	rm *.o MiniProject1
