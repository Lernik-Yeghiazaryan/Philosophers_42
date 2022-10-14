/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leyeghia <leyeghia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:30:13 by leyeghia          #+#    #+#             */
/*   Updated: 2022/10/13 20:20:59 by leyeghia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo(void *data)
{
	t_philo	*philo;

	philo = data;
	if (philo->index % 2 == 1)
		ft_usleep(philo->time_to_eat - 10);
	while (1)
	{
		pthread_mutex_lock(philo->left);
		ft_print(philo, "has taken a fork");
		pthread_mutex_lock(philo->right);
		ft_print(philo, "has taken a fork");
		ft_print(philo, "is eating");
		++philo->eat_count;
		philo->gap = get_time();
		ft_usleep(philo->time_to_eat);
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
		ft_print(philo, "is sleeping");
		ft_usleep(philo->time_to_sleep);
		ft_print(philo, "is thinking");
	}
	return (0);
}

int	main(int ac, char **av)
{
	int					i;
	t_arrt				*node;

	i = -1;
	if ((ac != 5 && ac != 6) || !checking(av))
		return (0);
	node = (t_arrt *)malloc(sizeof(t_arrt));
	if (!create_fork(node, ft_atoi(av[1])) || create_phil(node, ft_atoi(av[1])))
		return (0);
	parsing(av, node->philo);
	ft_philos_timers(node);
	while (++i < node->philo->n_o_p)
		if (pthread_create(&node->philo[i].tid, NULL, &philo, node->philo + i))
			return (0);
	i = -1;
	while (++i < node->philo->n_o_p)
		if (pthread_detach(node->philo[i].tid))
			return (0);
	while (1)
		if (ft_is_dead(node)
			|| (node->philo->ate_enough != 0 && ft_enough(node)))
			return (0);
	return (0);
}
