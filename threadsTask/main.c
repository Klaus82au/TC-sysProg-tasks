#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <limits.h>

void * sum_of_progression(void * arg){
	return (void *) (int)((1+(int)arg)/2.0*(int)arg);
}

int main(){
	int input;
	void * output;
	printf("Enter n:");
	scanf("%d", &input);

	pthread_t thread;
	pthread_attr_t tattr;
	int ret, size;
	size = PTHREAD_STACK_MIN;/* bytes enough?*/ 
	pthread_attr_setstacksize(&tattr, size);
	ret=pthread_create(&thread, NULL, sum_of_progression, (void*)input);
	if (ret){
		fprintf(stderr,"Error - pthread_create() return code: %d\n",ret);
        exit(EXIT_FAILURE);
	}
	pthread_join( thread, &output);

	printf("The result is : %d\n", (int *)output);
	return 0;
}     