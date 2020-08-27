mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
final_path := $(subst Makefile,,$(mkfile_path))

all:
	g++ -fPIC -shared libatesting.cpp -o libatesting.so
	g++ executableEdditing.cpp -L$(final_path) -Wl,-rpath=~$(final_path) -latesting

run:
	./a.out
clean:
	rm *.out *.so

tmp:
	g++ executableEdditing.cpp -L/home/loanwolf/ACM/demos/edditingExecutables/dynamic_library/ -Wl,-rpath=/home/loanwolf/ACM/demos/edditingExecutables/dynamic_library -latesting
