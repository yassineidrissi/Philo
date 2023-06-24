/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 23:42:31 by yassine           #+#    #+#             */
/*   Updated: 2023/06/24 17:39:00 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
typedef struct s_philo
{
    int id;
    int nb_meals;
    struct s_data *data;
}t_philo;

typedef struct s_data
{
    int nb_philo;
    int nb_meals;
    int tm_sleep;
    int tm_eat;
    int tm_die;
    pthread_t threads[250];    
    pthread_mutex_t fork[250];
    t_philo philo[250];
}t_data;

//********philo_srcs************///
void ft_parser(char ** av, t_data *data);
void handl_errors(int i);
void ft_fill_params_master(char **av, t_data *data);
void ft_fill_params_slive(t_data *data, char **av, int i);
void* philosopher(void* arg);
void init_threads(t_data * data);
//********lib_srcs************///
int ft_isdigit(char c);
int ft_strisdigit(char *str);
int ft_atoi(char *str);


#endif
