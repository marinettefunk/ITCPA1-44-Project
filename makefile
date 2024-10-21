main: canidates.o votes.o main.o
	g++ -std=c++98 canidates.o votes.o main.o -o main

canidates.o: canidates.cpp canidates.h
	g++ -c canidates.cpp -std=c++98

votes.o: votes.cpp votes.h canidates.h
	g++ -c votes.cpp -std=c++98

main.o: main.cpp canidates.h votes.h
	g++ -c main.cpp -std=c++98

clean:
	rm -f *.o main

all: main
	./main