#include <sys/mman.h>
#include <string.h>
#include <unistd.h>

void func(char * ptr) {
	unsigned long sz = getpagesize() - 1; 
	void *pg = (void *) ((long) ptr & ~sz); 

	char* kirby = "ACM\n";
	mprotect(pg, strlen(kirby), PROT_WRITE | PROT_READ); 
	// This tells the OS that a page is readable/write
	strcpy(ptr, kirby); 
}
