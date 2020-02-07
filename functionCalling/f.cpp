#include <stdio.h>

#pragma GCC diagnostic ignored "-Wunused-but-set-variable"

void second();

void f() {
    void *buf[1];
    buf[2] = (char *) second + 9;
}
