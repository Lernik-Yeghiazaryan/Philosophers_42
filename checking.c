/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leyeghia <leyeghia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 18:32:29 by leyeghia          #+#    #+#             */
/*   Updated: 2022/10/04 14:44:07 by leyeghia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *s)
{
	int	val;
	int	i;
	int	sign;

	val = 0;
	sign = 1;
	i = 0;
	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-' || s[i] == '+')
		if (s[i++] == '-')
			sign = -1;
	while (s[i] > 47 && s[i] < 58)
	{	
		val = 10 * val + (s[i] - 48);
		i++;
	}
	return (sign * val);
}

int	is_alpha(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (0);
	return (1);
}

int	checking(char **line)
{
	int	i;

	i = 0;
	while (line && line[++i])
	{
		if (ft_atoi(line[i]) <= 0 || !is_alpha(line[i]))
		{
			write (1, "Wrong argument\n", 15);
			return (0);
		}	
	}
	return (1);
}

int	ft_is_dead(t_arrt *node)
{
	int	i;

	i = -1;
	while (++i < node->philo->n_o_p)
	{
		if (get_time() - node->philo[i].gap > node->philo[i].t_t_d)
		{
			usleep(10);
			printf("%llu\t%d  is died\n", get_time() - node->philo[i].time,
				node->philo[i].index + 1);
			return (1);
		}
	}
	return (0);
}

int	ft_enough(t_arrt *node)
{
	int	i;

	i = -1;
	while (++i < node->philo->n_o_p)
	{
		if (node->philo[i].eat_count < node->philo->ate_enough)
			return (0);
	}
	printf("%llu\tAll philosophers ate enough\n", get_time() - node->philo->time);
	return (1);
}
