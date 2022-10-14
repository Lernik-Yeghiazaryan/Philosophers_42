/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leyeghia <leyeghia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:53:30 by leyeghia          #+#    #+#             */
/*   Updated: 2022/10/04 14:06:16 by leyeghia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print(t_philo *philo, char *str)
{
	pthread_mutex_lock(philo->p_write);
	printf("%llu\t%d  %s\n", get_time() - philo->time,
		philo->index + 1, str);
	pthread_mutex_unlock(philo->p_write);
}

void	ft_philos_timers(t_arrt *node)
{
	long long	timer;
	int			i;

	i = -1;
	timer = get_time();
	while (++i < node->philo->n_o_p)
	{
		node->philo[i].gap = timer;
		node->philo[i].time = timer;
	}
}
