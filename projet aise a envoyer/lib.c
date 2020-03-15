#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <err.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

void * malloc(size_t size)
{
	int *plenth;
	int lenth = size + sizeof( size );//Ajouter une taille de (size) pour tenir la longueur
	plenth = mmap( 0, lenth, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0 );
	*plenth = lenth;                     // les 4 premiers octets contiennent la longueur.
	return (void*)(&plenth[1]);        // Memoire aprés variable de longueur.
}

void *realloc(void *ptr, size_t size)
{
	if (ptr == NULL) 
	{
        	return malloc(size);
    	} 	
	else if (size == 0) 
	{
        	free(ptr);
        	return NULL;
    	}
}
void * calloc(size_t nbrelem, size_t elemsize)
{
	void *p;
	p = malloc (nbrelem * elemsize);
	if (p == 0)
        	return (p);
	bzero (p, nbrelem * elemsize);
    	return (p);
}

void free(void *ptr)
{
	int *plenth = (int*)ptr;
	int lenth;
	plenth--;                          // atteignez le sommet de la memoire
    	lenth = *plenth;                     // lire la logueur
	munmap( (void*)plenth, lenth );
}


