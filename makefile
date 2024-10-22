main: candidates.o votes.o main.o
	g++ -std=c++98 candidates.o votes.o main.o -o main

candidates.o: candidates.cpp candidates.h
	g++ -c candidates.cpp -std=c++98

votes.o: votes.cpp votes.h candidates.h
	g++ -c votes.cpp -std=c++98

main.o: main.cpp candidates.h votes.h
	g++ -c main.cpp -std=c++98

clean:
	rm -f *.o main

all: main
	./main