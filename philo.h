/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 23:42:31 by yassine           #+#    #+#             */
/*   Updated: 2023/06/18 02:01:35 by yaidriss         ###   ########.fr       */
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
}t_philo;

void ft_parser(char ** av, t_philo *data);
void handl_errors(int i);
void ft_fill_params(t_philo *data, char **av, int i);

//********lib_srcs************///
int ft_isdigit(char c);
int ft_strisdigit(char *str);
int ft_atoi(char *str);


#endif
