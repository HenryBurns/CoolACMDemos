all: objects
	g++ executableEdditing.o test.o

objects: executableEdditing.o test.o
	g++ -c executableEdditing.cpp
	g++ -c test.cpp

clean:
	rm *.o a.out
