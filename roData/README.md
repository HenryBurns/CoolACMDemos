Run1:
------------------------

This is a really cool demo. The point of this is to demonstrate that
string literals are stored in the .rodata section of memory. If we
have two instances of the string "Test", they will point to the same
memory.

Now we can use mprotect to make these pages writable, and change this
memory. In doing so we change all instances of the string "Test" to
something else.

Outputs: "ACM\nACM\n"

Now what happens when we add a newline?


Run2:
------------------------

It turns out that things behave differently with newlines, and it has
to do with how printf handles '\n' characters. The newline character
hints to printf that it might be a good time to flush our buffer.
So printline tries to print "Test" normally, considers flushing,
and adds "\n"

This means that if all instances of "Test\n" are changed in .rodata,
we still have to find an instance of "Test".

Outputs: "ACM\nTest\n"


Run3:
------------------------
Now if we replace "Test\n" with "Test", and try to print "Test\n"
you'll notice that our new string gets printed instead (with an
additional newline).

Outputs: "ACM\nACM\n\n"
