/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 20:05:18 by yaidriss          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/07/19 15:09:55 by yaidriss         ###   ########.fr       */
=======
/*   Updated: 2023/07/19 17:38:20 by yaidriss         ###   ########.fr       */
>>>>>>> origin
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	philo_timestamp(t_philo *philo, char *action)
{
	useconds_t	time;
	bool		died;

	pthread_mutex_lock(&philo->data->lock);
	time = philo_get_time() - philo->data->init_time;
	pthread_mutex_unlock(&philo->data->lock);
<<<<<<< HEAD
	pthread_mutex_lock(&philo->data->death);
	died = philo->data->died;
	pthread_mutex_unlock(&philo->data->death);
	if (died)
=======
	if (action[10] == 'd')
>>>>>>> origin
	{
		// pthread_mutex_lock(&philo->data->writing);
		printf("\033[1;39m%06u\033[0;39m  \033[1;96m%03d  \033[0;39m%s\n", \
			time, philo->id + 1, action);
<<<<<<< HEAD
		// pthread_mutex_unlock(&philo->data->writing);
=======
>>>>>>> origin
		return;
	}
	if (action[10] != 'd')
	{
		pthread_mutex_lock(&philo->data->writing);
		printf("\033[1;39m%06u\033[0;39m  \033[1;96m%03d  \033[0;39m%s\n", \
			time, philo->id + 1, action);
		pthread_mutex_unlock(&philo->data->writing);
	}
	// pthread_mutex_lock(&philo->data->lock);
	if(action[10] == 'e')
	{
		pthread_mutex_lock(&philo->data->meal);
		philo->nb_meals++;
		pthread_mutex_unlock(&philo->data->meal);
		// printf("the nb_meals is %d and philo id: is %d\n", philo->nb_meals, philo->id + 1);
<<<<<<< HEAD
=======
		pthread_mutex_lock(&philo->data->time);
		philo->last_meal = philo_get_time();
		pthread_mutex_unlock(&philo->data->time);
		ft_usleep(philo->data->tm_eat);
		// pthread_mutex_unlock(&philo->data->lock);
		// pthread_mutex_lock(&philo->data->lock);
>>>>>>> origin
		// pthread_mutex_unlock(&philo->data->lock);
		pthread_mutex_lock(&philo->data->time);
		philo->last_meal = philo_get_time();
		pthread_mutex_unlock(&philo->data->time);
		ft_usleep(philo->data->tm_eat);
	}
	// {
	// 	pthread_mutex_lock(&philo->data->writing);
	// 	printf("\033[1;39m%06u\033[0;39m  \033[1;96m%03d  \033[0;39m%s\n", \
	// 		time, philo->id + 1, action);
	// 	pthread_mutex_unlock(&philo->data->writing);
	// }
	// else
	// pthread_mutex_unlock(&philo->data->lock);
}
