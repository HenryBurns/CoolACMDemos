We declare a local variable in f() so that we know where we are on the stack
we then index past that so that we overwrite the return address and replace
it with a different function call.

You can see why we need 9 bytes if you run

    objdump -d ./a.out

Then look at the function second (with some extra garbage letters).
On my architecture there are 9 bytes in second before the call to printf().
Therefore if we add 9, we can skip return directly to the printf() in second

NOTE: Right now this one isn't working on my laptop. My assumption is that
we have some other data stored on the stack before the return address.

TLDR: We overwrite the return address while in f() and change
      our return address to the printf() in second.
