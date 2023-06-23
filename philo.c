/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 23:38:50 by yassine           #+#    #+#             */
/*   Updated: 2023/06/23 18:12:25 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
    t_philo data;

    if (ac != 6 && ac != 5)
        handl_errors(1);
    ft_parser(av, &data);
    printf("im working ");
}
