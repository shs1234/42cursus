#include "philo.h"

long	get_time_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	main(void)
{
	while (1)
	{
		printf("%ld\n", get_time_ms());
	}
}