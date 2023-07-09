/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 23:38:50 by yassine           #+#    #+#             */
/*   Updated: 2023/07/09 04:51:29 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_sleep(t_philo *philo)
{
    philo_timestamp(philo, PHILO_SLEEP);
    ft_usleep(philo->data->tm_sleep);
}

void ft_think(t_philo *philo)
{
   philo_timestamp(philo, PHILO_THINK);
}

void ft_eat(t_philo *philo)
{
    philo_timestamp(philo, PHILO_EAT);
    ft_usleep(philo->data->tm_eat);
}

void* start_thread(void* arg)
{
    t_philo *philo = (t_philo*)arg;

    if (philo->id % 2 == 0)
        usleep(100);
    while(1)
    {
        // printf("philo %d :i'm take 1\n", philo->id); 
        pthread_mutex_lock(&philo->data->fork[philo->id]);
        // printf("philo %d :i'm take 2\n", philo->id);
        pthread_mutex_lock(&philo->data->fork[(philo->id + 1) % philo->data->nb_philo]);
        philo_timestamp(philo, PHILO_TAKE_FORK);
        ft_eat(philo);//!need to craate my own speep function
        // printf("philo %d :i'm untake 1\n", philo->id);
        pthread_mutex_unlock(&philo->data->fork[philo->id]);
        // printf("philo %d :i'm untake 2\n", philo->id);
        pthread_mutex_unlock(&philo->data->fork[(philo->id + 1) % philo->data->nb_philo]);
        ft_sleep(philo);
        ft_think(philo);
    }
    return NULL;
}

void init_threads(t_data * data)
{
    int i;

    i = -1;
    while (++i < data->nb_philo)
    {
        pthread_create(data->threads + i, NULL, start_thread, data->philo + i);
        usleep(100);
    }
        //! if there is a probleme sleep also here 
        // Pass the t_philo struct as the argument to the philosopher function

    // Wait for the threads to finish
    i = -1;
    while (++i < data->nb_philo)
        pthread_join(data->threads[i], NULL);
     
}

void ft_monitoring(t_data *data)
{
    while(1)
    {
        pthread_mutex_lock(&data->eat_count);
		eat_c = philo->data->eat_count;
		pthread_mutex_unlock(&philo->data->eat_count_lock);
		pthread_mutex_lock(&philo->last_meal_lock);
		last_meal = philo->last_meal;
		pthread_mutex_unlock(&philo->last_meal_lock);
		if (philo_get_time() - philo->data->init_time - last_meal >= \
			philo->data->die_time || eat_c == \
			philo->data->philo_count * philo->data->repeat_count)
		{
			pthread_mutex_lock(&philo->data->died_lock);
			philo->data->died = 1;
			pthread_mutex_unlock(&philo->data->died_lock);
			if (eat_c != philo->data->philo_count * philo->data->repeat_count)
				philo_timestamp(start, PHILO_DIE, 0);
			return (NULL);
		}
    }
}

int main(int ac, char **av)
{
    t_data data;

    if (ac != 6 && ac != 5)
        handl_errors(1);
    ft_parser(av, &data);
    init_threads(&data);
    // ft_monitoring(&data);
    printf("im working ");
}
