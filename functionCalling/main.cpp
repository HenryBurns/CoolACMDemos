#include <stdio.h>

void f();

void first() {
    f();
    printf("First!\n");
}

void second() {
    f();
    printf("Second!\n");
}

int main() {
    first();
    printf("Main!\n");
}
