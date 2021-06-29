#include "philo.h"

int main(void)
{
	struct timeval	test;
	struct timeval	test2;

	while (1)
	{
		gettimeofday(&test, NULL);
		for(int i = 0; i < 50; i++)
		{
			;
		}
		gettimeofday(&test2, NULL);

		printf("%d\n", test2.tv_usec - test.tv_usec);
	}


	return (0);
}
