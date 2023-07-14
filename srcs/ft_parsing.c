/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 23:57:29 by yassine           #+#    #+#             */
/*   Updated: 2023/07/14 18:25:11 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void ft_fill_params_slive(t_data *data, char **av, int i)
{
    if (i == 1)
        data->nb_philo = ft_atoi(av[i]);
    else if (i == 2)
        data->tm_die = ft_atoi(av[i]);
    else if (i == 3)
        data->tm_eat = ft_atoi(av[i]);
    else if (i == 4 && !av[i + 1])
        data->tm_sleep = ft_atoi(av[i]);
    else if (i == 4)
    {
        data->tm_sleep = ft_atoi(av[i]);
        data->max_meals = -1;
    }
    else
        data->max_meals = ft_atoi(av[i]);    
}

void ft_fill_params_master(char **av, t_data *data)
{
    int i;
    
    i = 0;
    while (av[++i])
    {
        if (!ft_strisdigit(av[i]))
            handl_errors(1);
        else
            ft_fill_params_slive(data, av, i);
    }
    if (data->nb_philo < 2 || data->nb_philo > 200 || data->max_meals < 0 || data->tm_die < 0 || data->tm_eat < 0 || data->tm_sleep < 0)
        handl_errors(1);
}

void ft_init_mutex(t_data *data)
{
    int i;

    i = 0;
    while(i < data->nb_philo)
    {
        pthread_mutex_init(&data->fork[i], NULL);
        i++;
    }
    pthread_mutex_init(&data->writing, NULL);
    pthread_mutex_init(&data->death, NULL);
    pthread_mutex_init(&data->meal, NULL);
    pthread_mutex_init(&data->lock, NULL);
    // pthread_mutex_init(&data->print, NULL);
}

void ft_parser(char **av, t_data *data)
{
    int i;

    i = 0;
    ft_fill_params_master(av, data);
    ft_init_mutex(data);
    while(i < data->nb_philo)
    {
        // data->fork[i] = 1;
        data->philo[i].id = i;
        data->philo[i].data =  data;
        data->philo[i].nb_meals = 0;
        i++;
    }
    data->died = 0;
    // printf("%d\n", data->philo[1].data->nb_philo);
}