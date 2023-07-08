/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 23:38:50 by yassine           #+#    #+#             */
/*   Updated: 2023/07/08 18:39:25 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_sleep(t_philo *philo)
{
    int i;

    i = 0; 
    printf(PHILO_SLEEP);
    printf("philo %d :i'm sleeping\n", philo->id);
    ft_usleep(philo->data->tm_sleep);
}

void ft_think(t_philo *philo)
{
    printf(PHILO_THINK);
    printf("philo %d :i'm thinking\n", philo->id);
}

void ft_eat(t_philo *philo)
{
    printf(PHILO_EAT);
    printf("philo %d :i'm eating\n", philo->id);
    ft_usleep(philo->data->tm_eat);
}

void* start_thread(void* arg)
{
    t_philo *philo = (t_philo*)arg;

    if (philo->id % 2 == 0)
        usleep(3000);
    while(1)
    {
        printf("philo %d :i'm take 1\n", philo->id); 
        pthread_mutex_lock(&philo->data->fork[philo->id - 1]);
        printf("philo %d :i'm take 2\n", philo->id);
        if (philo->id == philo->data->nb_philo)
            pthread_mutex_lock(&philo->data->fork[0]);
        else
            pthread_mutex_lock(&philo->data->fork[philo->id]);
        ft_eat(philo);//!need to craate my own speep function
        printf("philo %d :i'm untake 1\n", philo->id);
        pthread_mutex_unlock(&philo->data->fork[philo->id - 1]);
        printf("philo %d :i'm untake 1\n", philo->id);
        if (philo->id == philo->data->nb_philo)
            pthread_mutex_unlock(&philo->data->fork[0]);
        else
            pthread_mutex_unlock(&philo->data->fork[philo->id]);
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
