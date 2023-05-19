#include <stdio.h>
#include <sys/time.h>

int	main(void)
{
	struct timeval	currentTime;

	gettimeofday(&currentTime, NULL);
	printf("Current time: %ld seconds, %ld microseconds\n", currentTime.tv_sec,
			currentTime.tv_usec);
	return (0);
}
