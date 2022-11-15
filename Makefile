main: main.o inputGeneration.o outputComparison.o judge.o execute.o
	g++ -o main main.o inputGeneration.o outputComparison.o judge.o execute.o -g

main.o: main.cpp
	g++ -c -o main.o main.cpp
inputGeneration.o: inputGeneration.cpp
	g++ -c -o inputGeneration.o inputGeneration.cpp
outputComparison.o: outputComparison.cpp
	g++ -c -o outputComparison.o outputComparison.cpp
judge.o: judge.o
	g++ -c -o judge.o judge.cpp
execute.o: execute.o
	g++ -c -o execute.o execute.cpp	
clean:
	rm *.o main