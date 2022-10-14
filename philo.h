/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leyeghia <leyeghia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 18:32:44 by leyeghia          #+#    #+#             */
/*   Updated: 2022/10/04 14:07:33 by leyeghia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>

typedef pthread_mutex_t	t_mutex;

typedef struct s_philo
{
	int					index;
	int					ate_enough;
	int					eat_count;
	int					n_o_p;
	long long			t_t_d;
	long long			time_to_eat;
	long long			time_to_sleep;
	long long			time;
	long long			gap;
	pthread_t			tid;
	t_mutex				*left;
	t_mutex				*right;
	t_mutex				*p_write;
}						t_philo;

typedef struct s_arrt
{
	t_mutex				*forks;
	t_philo				*philo;
	t_mutex				*t_write;
}						t_arrt;

int						checking(char **line);
int						ft_atoi(const char *str);
void					parsing(char **av, t_philo *val);
void					ft_usleep(long long num);
int						create_fork(t_arrt *node, int len);
int						create_phil(t_arrt *node, int len);
long long				get_time(void);
void					ft_print(t_philo *philo, char *str);
int						ft_is_dead(t_arrt *node);
void					ft_philos_timers(t_arrt *node);
int						ft_enough(t_arrt *node);

#endif
