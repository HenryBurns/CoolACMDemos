We declare a local variable in f() so that we can have pointers overwrite
the stack.

We use second + 9, because we looked at

    objdump -d ./a.out

Then look at the function second (with some name mangling letters).
On my architecture there are 9 bytes in second before the call to printf().
Therefore if we add 9, get the address in second() where printf starts.

Run1:
-------------
If you overwrite buf[1], it will cause an error saying that you are
smashing the stack. Then the program will die.


Run2:
-------------
Here buf[1] is the stack canary,
     buf[2] is the stack frame pointer,
     buf[3] is the return address.

Alternatively if you compile with -f-no-stack-protector then

     buf[1] is the stack frame pointer from first()
     buf[2] is the return address from first().

For the rest of the demo, we assume that you make guardless

The returns look something like this:

f()--> second --> main

Run3:
-------------
This demo gets more interesting when you overwrite buf[4] instead of buf[2]

     buf[3] is the stack frame pointer from main()
     buf[4] is the return address from main().
            that means that if we overwrite it, we will print
            "First\nSecond\n"


f()--> first--> second --> glibc

Run4:
-------------
Now what if we overwrite the return address of main()? (buf[6])

     buf[5] is the stack frame pointer from glibc()
     buf[6] is the return address from glibc()
            If we overwrite it, we print "First\nMain\nSecond\n"

f()--> first --> main --> second --> ??!?! Segmentation fault ??!?!

TLDR: We overwrite the return address while in f() and change
      our return address to the printf() in second.
