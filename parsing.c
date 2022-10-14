/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leyeghia <leyeghia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:00:44 by leyeghia          #+#    #+#             */
/*   Updated: 2022/10/04 14:05:00 by leyeghia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parsing(char **av, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < ft_atoi(av[1]))
	{
		philo[i].n_o_p = ft_atoi(av[1]);
		philo[i].t_t_d = ft_atoi(av[2]);
		philo[i].time_to_eat = ft_atoi(av[3]);
		philo[i].time_to_sleep = ft_atoi(av[4]);
		if (av[5] != NULL)
			philo[i].ate_enough = ft_atoi(av[5]);
		else
			philo[i].ate_enough = 0;
	}
}
