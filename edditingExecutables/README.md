The idea here is to show off how c++ files are actually compiled.

Since o files comply with ELF standard they are basically executables,
the linker just needs to resolve any calls to a different file's function
firs.

Notice that for a statically linked file you can edit the .o file.
For all we care it looks a litte something like this.

-------------------------
Functions and byte code
-------------------------
Symbol Table (Name : address)
-------------------------
Relocation Table (Name : address)
-------------------------

Here the symbol table contains the adresses of functions and global 
that are defined in the current cpp/c file being defined.

The relocation Table contains the function calls that need to be resolved,
as they are defined in other files. This means that we can open the .o file
in ViM, and directly edit the relocation table (it has the function call in
ASCII). The only thing to be carefull of is changing the size of the
O file. If you make the name shorter or longer the linker will not link
the new o files.

This is why we change the call from foo() to goo() in 

TLDR: The executableEdditing.o file is looking for foo(), but doesn't know
where it is. We sneak into this file and say, nah you're looking for goo().
The linker sees the o file is looking for goo() and makes everything work.
