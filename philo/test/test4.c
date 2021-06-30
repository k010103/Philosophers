#include "philo.h"

int main(void)
{
	struct timeval	test;
	struct timeval	test2;

	while (1)
	{
		gettimeofday(&test2, NULL);
		usleep(200);
		gettimeofday(&test, NULL);

		printf("%d\n", test.tv_usec - test2.tv_usec);
	}


	return (0);
}
