/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 23:38:50 by yassine           #+#    #+#             */
/*   Updated: 2023/07/14 18:31:32 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void ft_sleep(t_philo *philo)
// {
//     philo_timestamp(philo, PHILO_SLEEP);
//     ft_usleep(philo->data->tm_sleep);
// }

// void ft_think(t_philo *philo)
// {
//    philo_timestamp(philo, PHILO_THINK);
// }

// void ft_eat(t_philo *philo)
// {
//     philo_timestamp(philo, PHILO_EAT);
//     ft_usleep(philo->data->tm_eat);
// }

void* start_thread(void* arg)
{
    t_philo *philo = (t_philo*)arg;

    if (philo->id % 2 == 0)
        usleep(100);
    while(1)
    {
        pthread_mutex_lock(&philo->data->fork[philo->id]);
        pthread_mutex_lock(&philo->data->fork[(philo->id + 1) % philo->data->nb_philo]);
        philo_timestamp(philo, PHILO_TAKE_FORK);
        philo_timestamp(philo, PHILO_EAT);//!need to craate my own speep function
        pthread_mutex_unlock(&philo->data->fork[philo->id]);
        pthread_mutex_unlock(&philo->data->fork[(philo->id + 1) % philo->data->nb_philo]);
        philo_timestamp(philo, PHILO_SLEEP);
        ft_usleep(philo->data->tm_sleep);
        philo_timestamp(philo, PHILO_THINK);
    }
    return NULL;
}

void ft_monitoring(t_data *data)
{
    int i = -1;
    while(1)
    {
        pthread_mutex_lock(&data->meal);
        if (data->philo[i % data->nb_philo].last_meal >= data->tm_eat || data->philo[++i % data->nb_philo].nb_meals >= data->max_meals)
        {
            printf("im here the last meal is %d and tm_eat is %d, nb meal is %d\n",data->philo[i % data->nb_philo].last_meal, data->tm_eat, data->philo[i % data->nb_philo].nb_meals);
            pthread_mutex_lock(&data->lock);
            data->died = true;
            pthread_mutex_unlock(&data->lock);
            pthread_mutex_lock(&data->writing);
            philo_timestamp(&data->philo[i], PHILO_DIE);
            pthread_mutex_unlock(&data->writing);
        }
        pthread_mutex_unlock(&data->meal);
        // pthread_mutex_lock(&data->eat_count);
		// eat_c = philo->data->eat_count;
		// pthread_mutex_unlock(&philo->data->eat_count_lock);
		// pthread_mutex_lock(&philo->last_meal_lock);
		// last_meal = philo->last_meal;
		// pthread_mutex_unlock(&philo->last_meal_lock);
		// if (philo_get_time() - philo->data->init_time - last_meal >= \
		// 	philo->data->die_time || eat_c == \
		// 	philo->data->philo_count * philo->data->repeat_count)
		// {
		// 	pthread_mutex_lock(&philo->data->died_lock);
		// 	philo->data->died = 1;
		// 	pthread_mutex_unlock(&philo->data->died_lock);
		// 	if (eat_c != philo->data->philo_count * philo->data->repeat_count)
		// 		philo_timestamp(start, PHILO_DIE);
		// 	return (NULL);
		// }
    }
}

void init_threads(t_data * data)
{
    int i;

    i = -1;
    while (++i < data->nb_philo)
    {
        data->philo[i].last_meal = philo_get_time();
        pthread_create(data->threads + i, NULL, start_thread, data->philo + i);
        // usleep(100);
    }
        //! if there is a probleme sleep also here 
        // Pass the t_philo struct as the argument to the philosopher function
    ft_monitoring(data);
    // Wait for the threads to finish
    i = -1;
    while (++i < data->nb_philo)
        pthread_join(data->threads[i], NULL);
     
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
