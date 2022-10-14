/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leyeghia <leyeghia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:02:43 by leyeghia          #+#    #+#             */
/*   Updated: 2022/10/03 18:47:08 by leyeghia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_fork(t_arrt *node, int len)
{
	int	i;

	i = -1;
	node->forks = malloc(sizeof(t_mutex) * len);
	node->t_write = malloc(sizeof(t_mutex));
	pthread_mutex_init(node->t_write, NULL);
	while (++i < len)
	{
		if (pthread_mutex_init(node->forks + i, NULL))
			return (0);
	}
	return (1);
}

int	create_phil(t_arrt *node, int len)
{
	int	i;
	int	n;

	i = 0;
	n = len - 1;
	node->philo = malloc(sizeof(t_philo) * len);
	if (!node->philo)
		return (0);
	node->philo[0].p_write = node->t_write;
	node->philo[0].index = 0;
	node->philo[0].left = node->forks;
	node->philo[0].right = node->forks + n;
	while (++i <= n)
	{
		node->philo[i].p_write = node->t_write;
		node->philo[i].index = i;
		node->philo[i].left = node->forks + i;
		node->philo[i].right = node->forks + (i - 1);
	}
	return (0);
}
