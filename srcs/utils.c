#include "../philo.h"

unsigned long get_time(void)
{
    struct timeval time;
    gettimeofday(&time, NULL);
	return ((time.tv_sec * (unsigned long)1000) + (time.tv_usec / 1000));
}

void my_sleep(t_data *data)
{
    // struct timeval time;
    while(get_time() - data->last_meal <  data->tm_die)
        usleep(100);
}