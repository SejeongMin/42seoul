# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_params
{
	pthread_mutex_t	m1;
	pthread_mutex_t	m2;
} t_params;

void	*routine(t_params *params)
{
	while(1)
	{
		pthread_mutex_lock(&(params->m1));
		printf("thread1 m1\n");
		sleep(1);
		pthread_mutex_unlock(&(params->m1));
		sleep(1);
	}
	return (0);
}

void	*routine2(t_params *params)
{
	while(1)
	{
		pthread_mutex_lock(&(params->m1));
		printf("thread2 m1\n");
		sleep(1);
		pthread_mutex_lock(&(params->m2));
		

		printf("thread2 m2\n");
		sleep(1);
		pthread_mutex_unlock(&(params->m2));
		sleep(1);
		pthread_mutex_unlock(&(params->m1));
		sleep(1);
	}
}

void	*routine3(t_params *params)
{
	while(1)
	{
		pthread_mutex_lock(&(params->m2));
		printf("thread3 m2\n");
		sleep(1);
		pthread_mutex_unlock(&(params->m2));
		sleep(2);
	}
}

int main(void)
{
	t_params *params;
	params = (t_params *)malloc(sizeof(t_params));
	
	pthread_t t1;
	pthread_t t2;
	pthread_t t3;

	pthread_mutex_init(&(params->m1), 0);
	pthread_mutex_init(&(params->m2), 0);
	pthread_create(&t1, 0, (void*)routine, params);
	pthread_create(&t2, 0, (void*)routine2, params);
	pthread_create(&t3, 0, (void*)routine3, params);

	pthread_join(t2, 0);
	pthread_join(t3, 0);
	pthread_join(t1, 0);
}
