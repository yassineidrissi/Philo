/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 20:05:18 by yaidriss          #+#    #+#             */
/*   Updated: 2023/07/09 03:29:31 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	philo_timestamp(t_philo *philo, char *action)
{
	useconds_t	time;
	int			died;
	int			eat_count;
	pthread_mutex_lock(&philo->data->writing);
	pthread_mutex_lock(&philo->data->death);
	died = philo->data->died;
	pthread_mutex_lock(&philo->data->eat_count);
	eat_count = philo->nb_meals;
	time = philo_get_time() - philo->data->init_time;
	if (philo->nb_meals != philo->data->max_meals && (!died || action[7] == 'd'))
	{
		printf("\033[1;39m%06u\033[0;39m  \033[1;96m%03d  \033[0;39m%s\n", \
			time, philo->id + 1, action);
	}
	if (action[10] == 'e')
		philo->nb_meals++;
	pthread_mutex_unlock(&philo->data->eat_count);
	pthread_mutex_unlock(&philo->data->death);
	pthread_mutex_unlock(&philo->data->writing);
}
