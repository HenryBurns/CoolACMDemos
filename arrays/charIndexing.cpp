#include <stdio.h>

int main() {
    int a[3][5] = {
     0, 1, 2, 3, 4,
     5, 6, 7, 8, 9,
     10, 11, 12, 13, 14};

    printf("%d\n", a[1][1]);
    printf("%d\n", 1[a][1]);
    printf("%d\n", 1[1[a]]);

    for (char i = 0; i < 3; i++) {
        for (char j = 0; j < 5; j++) {
            printf("%d\n", a[i][j]);
            printf("%d\n", i[a][j]);
            printf("%d\n", *((*(i + a)) + j));
        }
    }
}

