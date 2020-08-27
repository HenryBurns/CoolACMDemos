#include <stdio.h>

void func(char *);

void first() {
	func("Test");
	char* ptr2 = "Test";

	printf("%s", ptr2);
	printf("Test");
}

void second() {
	const char* ptr2 = "Test\n";
	func("Test\n");

	printf("%s", ptr2);
	printf("Test\n");
}

void third() {
	const char* ptr2 = "Test";
	func("Test");

	printf("%s", ptr2);
	printf("Test\n");
}

int main() {
	first();
	// second();
	// third();
}
