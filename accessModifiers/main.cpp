#include <iostream>
// #include "header.h"

class Tmp {
	int a; // private
private:
	int b;
public:
	int c;
};

int main() {
	Tmp tmp;
	tmp.a = 4;
	tmp.b = 4;
	tmp.c = 4;

	auto i = 2.2;

	std::cout << "I: " << i << std::endl;

	if(true) {
		std::cout << "This should always print TRUE" << std::endl;
	} else {
		std::cout << "This should never print" << std::endl;
	}
}
