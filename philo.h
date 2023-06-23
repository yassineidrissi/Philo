/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 23:42:31 by yassine           #+#    #+#             */
/*   Updated: 2023/06/23 23:05:40 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_philo
{
    unsigned int nb_philo;
    unsigned int nb_meals;
    unsigned int tm_sleep;
    unsigned int tm_eat;
    unsigned int tm_die;    
    unsigned int fork;
    int *forks;
    int *philo;
}t_philo;

typedef struct s_table
{
    t_philo *data;
}t_table;

void ft_parser(char ** av, t_philo *data);
void handl_errors(int i);
void ft_fill_params_master(char **av, t_philo *data);
void ft_fill_params_slive(t_philo *data, char **av, int i);

//********lib_srcs************///
int ft_isdigit(char c);
int ft_strisdigit(char *str);
int ft_atoi(char *str);


#endif
