#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

void *thread_1(void *arg)
{
    printf("Nous sommes dans le thread.\n");

    /* Pour enlever le warning */
    (void) arg;
    pthread_exit(NULL);
}
malloc_sys (int * tableau)

{
	int * tab;
	int taille_tab;
	
	tab = (int *) calloc (taille_tab, sizeof (int));
}

int main(int argc, char **argv)
{
	 pthread_t thread1;

    

    if(pthread_create(&thread1, NULL, thread_1, NULL) == -1) {
	perror("pthread_create");
	return EXIT_FAILURE;
    }
  
  	//declaration du tableau
  	size_t taille_tab = 10000000;
	int * tab;
	
	tab = (int *) calloc (taille_tab, sizeof (int));

	

	//appel a la fonction
	float temps;

	clock_t debut=clock();
	malloc_sys(*tab);
	free (tab);
	int pthread_join(pthread_t th, void **thread_return);
	clock_t final=clock();
	temps=(float)(final-debut);

	printf("\nle temps d'execution est %f ms \n", temps);


  return 0;
}
