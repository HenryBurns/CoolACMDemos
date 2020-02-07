The idea here is that indexing an array is just pointer arithmatic.
Consider a[1] = a + 1 = *(a + 1). Since we are adding a pointer to a non
pointer we must do pointer arithmatic. This means we do a + 1 * sizeof 
type that a points to.

therefore 1[A] = 1 + a = *(1 + a)

That means that all 3 of these are equivalent

    printf("%d\n", a[1][1]);
    printf("%d\n", 1[a][1]);
    printf("%d\n", 1[1[a]]);

All of these statements essentiall convert to something like this

*((*(a + 1)) + 1)
*((*(1 + a)) + 1)
*(1 + (*(1 + a)))

These 3 statements show a that in practice. Because of commutativity, it
doesn't matter the order in which we add this stuff. (And we always end
up doing the same pointer arithmatic)

    printf("%d\n", a[i][j]);
    printf("%d\n", i[a][j]);
    printf("%d\n", *((*(i + a)) + j));

This works even with chars because it's treated as an unsigned int for
pointer arithmatic.

ALL CREDIT FOR THIS CODE GOES TO PROFESSOR KENNITH CHIU
