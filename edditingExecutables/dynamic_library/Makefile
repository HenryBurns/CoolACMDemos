all:
	g++ -fPIC -shared libatesting.cpp -o libatesting.so
	g++ executableEdditing.cpp -L/home/loanwolf/ACM/demos/edditingExecutables/dynamic_library/ -Wl,-rpath=/home/loanwolf/ACM/demos/edditingExecutables/dynamic_library -latesting

run:
	./a.out
clean:
	rm *.out *.so
