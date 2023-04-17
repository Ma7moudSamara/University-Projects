main: main.o
	g++ main.o -lglut -lGL -lGLU -lm -o main

main.o: main.cpp
	g++ -c main.cpp -lglut -lGLU -lGL -lm

run: main
	./main inputData.txt

clean:
	rm *.o main


