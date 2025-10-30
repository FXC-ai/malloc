#include <pthread.h>
#include <stdio.h>
#define MAX 100000

pthread_mutex_t mutex;

typedef struct s_test_philo
{

	int *count;
	int id_thread;

} t_test_philo;

void *routine(void *test_philo)
{
	t_test_philo *cpy_test_philo = (t_test_philo *) test_philo;
	int i;

	printf("Début de processus pour le thread : %d\n", cpy_test_philo->id_thread);
	
	i = 0;
	while (i < MAX)
	{
        pthread_mutex_lock(&mutex);
		(*(cpy_test_philo->count))++;
		pthread_mutex_unlock(&mutex);
		i++;
	}
	printf("Fin de processus %d pour le thread %d\n", *(cpy_test_philo->count), cpy_test_philo->id_thread);
	
	return (NULL);
}

int main()
{

	void *ptr = malloc(23);

	free(ptr);

	void *ptr1 = realloc(27);


	return 0;
}