/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 23:38:50 by yassine           #+#    #+#             */
/*   Updated: 2023/07/08 13:25:57 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_sleep(t_philo *philo)
{
    int i;

    i = 0;
    while (i < philo->data->tm_sleep)
    {
        printf(PHILO_SLEEP);
        printf(",the philo %d\n", philo->id);
        usleep(1000);
        i++;
    }
}

void ft_think(void)
{
    printf(PHILO_THINK);
}

void* start_thread(void* arg)
{
    t_philo *philo = (t_philo*)arg;

    if (philo->id % 2 == 0)
        usleep(3000);
    while(1)
    {
        pthread_mutex_lock(philo->data->fork + philo->id);
        printf("philo %d :i'm take 1\n", philo->id); 
        pthread_mutex_lock(philo->data->fork + philo->id + 1);
        printf("philo %d :i'm take 2\n", philo->id);
        usleep(philo->data->tm_eat);//!need to craate my own speep function
        pthread_mutex_unlock(philo->data->fork + philo->id);
        printf("philo %d :i'm untake 1\n", philo->id);
        pthread_mutex_unlock(philo->data->fork + philo->id + 1);
        printf("philo %d :i'm untake 1\n", philo->id);
        ft_sleep(philo);
        ft_think();
    }
    return NULL;
}

void init_threads(t_data * data)
{
    int i;

    i = -1;
    while (++i < data->nb_philo)
        pthread_create(data->threads + i, NULL, start_thread, data->philo + i);
        //! if there is a probleme sleep also here 
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
