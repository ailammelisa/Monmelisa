#ifndef notrebib
#define notrebib

#include <stdlib.h>


void *notremalloc(size_t size);
void *realloc(void *ptr, size_t size);
void *calloc(size_t nmemb, size_t size);
void free(void *ptr);
#endif
