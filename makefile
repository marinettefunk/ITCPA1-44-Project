main: conversion.o calculation.o main.o
	g++ -std=c++98 conversion.o calculation.o main.o -o main

conversion.o: conversion.cpp conversion.h calculation.h
	g++ -c conversion.cpp -std=c++98

calculation.o: calculation.cpp calculation.h
	g++ -c calculation.cpp -std=c++98

main.o: main.cpp conversion.h
	g++ -c main.cpp -std=c++98

clean:
	rm -f *.o main

all: main
	./main