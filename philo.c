/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 23:38:50 by yassine           #+#    #+#             */
/*   Updated: 2023/06/25 12:17:50 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void* start_thread(void* arg)
{
    t_philo *philo = (t_philo*)arg;
    if (philo->id % 2 == 0)
        usleep(100);
    pthread_mutex_lock(philo->data->fork + philo->id);
    printf("philo %d :i'm take 1\n", philo->id); 
    pthread_mutex_lock(philo->data->fork + philo->id + 1);
    printf("philo %d :i'm take 2\n", philo->id);
    sleep(philo->data->tm_eat);
    pthread_mutex_unlock(philo->data->fork + philo->id);
    printf("philo %d :i'm untake 1\n", philo->id);
    pthread_mutex_unlock(philo->data->fork + philo->id + 1);
    printf("philo %d :i'm untake 1\n", philo->id);
    return NULL;
}

void init_threads(t_data * data)
{
    int i;

    i = -1;
    while (++i < data->nb_philo)
        pthread_create(data->threads + i, NULL, start_thread, data->philo + i);
        // Pass the t_philo struct as the argument to the philosopher function

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
    printf("im working ");
}
