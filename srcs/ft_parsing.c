/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 23:57:29 by yassine           #+#    #+#             */
/*   Updated: 2023/06/18 00:11:19 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void ft_fill_params(t_philo *data, char **av, int i)
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

void ft_parser(char **av, t_philo *data)
{
    int i;

    i = 0;
    while (av[++i])
    {
        if (!ft_strisdigit(av[i]))
            handl_errors(1);
        else
            ft_fill_params(data, av, i);
    }
}