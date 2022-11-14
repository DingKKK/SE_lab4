main: main.o inputGeneration.o outputComparison.o
	g++ -o main main.o inputGeneration.o outputComparison.o -g

main.o: main.cpp
	g++ -c -o main.o main.cpp
inputGeneration.o: inputGeneration.cpp
	g++ -c -o inputGeneration.o inputGeneration.cpp
outputComparison.o: outputComparison.cpp
	g++ -c -o outputComparison.o outputComparison.cpp

clean:
	rm *.o main