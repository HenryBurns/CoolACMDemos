Run1
-----------------------

First show compilation, and prove that printing the 2 numbers gives you the
same value. Afterwards, lets look at the compiler errors and try and see if
anyone knows what's going on (odds are nobody does).

Do a fun little demo with "One of these 3 options will compile, which one is it".

Run2
-----------------------

Demonstrate that only int64\_t will compile because of how the compiler looks
at integer literals. The compiler will ignore the - sign to figure out how much
memory the integer literal needs. The compiler will attempt to assign the value
9223372036854775808 to a 64 bit _signed_ integer, and then negate it. The problem
here is that this value does not fit in a 64 bit signed integer, (because of two's
complement).


So why does this cause anything to fail?

gcc expands int64\_t to int128 (a compiler specific type). Since this type is
compiler specific, std::cout cannot have an operator<<(\_\_int128) overload.
Therefore our compilation fails any time we have a 128 bit integer value.

int64\_t works because the rvalue gets expanded to 128 bits, then negated, and
then casted back to a 64 bit integer. Since there are no higher bits used, this
works.

Run3
-----------------------

Show that the types are as I claimed. Show all the decltype errors.
