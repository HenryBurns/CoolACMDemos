We have the same demo as above, but now it's with dynamically linked
libraries.

WHAT'S THE DIFFERENCE
-------------------------

1. A dynamically linked library is handled with relative jumps. This means
   that we need to know where vector/glibc is in order to jump to it. This
   means that the relocation table points to a jump table. This jump table
   is filled in at run time, so it has the address of vector/glibc code.


-------------------------
Functions and byte code
-------------------------
Symbol Table (Name : address)
-------------------------
Relocation Table (Name : jump table address)
-------------------------
Jump Table (adress of code in ram (filled at run time))
-------------------------

This means that we can edit the relocation table in the executable.
Since it still needs to find the function. (Notice that if you don't use the
right linker flags, you will get errors when running instead of when linking
together the o files). 

	g++ -fPIC -shared libatesting.cpp -o libatesting.so

Here -fPIC says use Position independent code (I.E. relative addresses for
all jumps so that we can use this as a shared library). -shared says that we
need this to be a shared library (meaning multiple cores can access it at
the same time).

	g++ executableEdditing.cpp -L/home/loanwolf/ACM/demos/edditingExecutables/dynamic_library/ -Wl,-rpath=/home/loanwolf/ACM/demos/edditingExecutables/dynamic_library -latesting

There are 4 flags we need to know here. 
    1. -L/Path/To/Directory/ (better if it's absolute)
    2. -Wl (A list of comma separated linker flags)
    3. -rpath=Path/To/Directory/ (We need this to tell the child process
            spawned where to look for this shared library. You'd think -L
            handles this, but long story short processes can be weird)
    4. -lLibraryNameMinusLib (This is a lowercase L, and it has the name of 
                              the library we are looking for. The linker
                              assumes that the library name is preceeded by
                              lib)

TLDR: Linker flags get weird for dynamically linked libraries, just use the
above flags and you'll be file. Search through the executable for the second
instance of foo(), and replace that with a call to goo(). This works on the
executable because everything is resolved at run time.

P.S. (The first foo() is probably just something the compiler left in case
      it was needed. For brownie points find out what that does)
