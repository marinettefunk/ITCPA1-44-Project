main: rollDice.o main.o
	g++ -std=c++98 rollDice.o main.o -o main

rollDice.o: rollDice.cpp rollDice.h
	g++ -c rollDice.cpp -std=c++98

main.o: main.cpp rollDice.h
	g++ -c main.cpp -std=c++98

clean:
	rm -f *.o main

all: main
	./main