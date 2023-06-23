/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 23:57:29 by yassine           #+#    #+#             */
/*   Updated: 2023/06/23 23:06:35 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void ft_fill_params_slive(t_philo *data, char **av, int i)
{
    if (i == 1)
        data->nb_philo = ft_atoi(av[i]);
    else if (i == 2)
        data->nb_philo = ft_atoi(av[i]);
    else if (i == 3)
        data->nb_philo = ft_atoi(av[i]);
    else if (i == 4)
        data->nb_philo = ft_atoi(av[i]);
    else if (i == 5)
        data->nb_philo = ft_atoi(av[i]);  
    else
        data->nb_philo = ft_atoi(av[i]);    
}

void ft_fill_params_master(char **av, t_philo *data)
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
    if (data->nb_philo < 2 || data->nb_philo > 200 || data->nb_meals < 0 || data->tm_die < 0 || data->tm_eat < 0 || data->tm_sleep < 0)
        handl_errors(1);
}

void ft_parser(char **av, t_philo *data)
{
    unsigned int i;

    i = 0;
    ft_fill_params_master(av, data);
    data->forks = malloc(sizeof(int) * data->nb_philo);
    data->philo = malloc(sizeof(int) * data->nb_philo);
    if (!data->forks || !data->philo)
        handl_errors(2);
    while(i < data->nb_philo)
    {
        data->forks[i] = 1;
        data->philo[i] = 0;
        i++;
    }
      
}