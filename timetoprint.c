/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timetoprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leyeghia <leyeghia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:25:59 by leyeghia          #+#    #+#             */
/*   Updated: 2022/10/02 18:42:54 by leyeghia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval		tm;

	gettimeofday(&tm, NULL);
	return ((tm.tv_sec * 1000) + (tm.tv_usec / 1000));
}

void	ft_usleep(long long num)
{
	long long	start;

	start = get_time();
	while (get_time() - start <= num)
		usleep(100);
}
