/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine_pat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:50:25 by brolivei          #+#    #+#             */
/*   Updated: 2023/07/11 14:50:29 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	pat_verify(t_args *args, int i, int x)
{
	if (x == 1)
	{
		pthread_mutex_lock(&args->verify);
		if (args->n_filo_done == args->n_philo)
		{
			pthread_mutex_unlock(&args->verify);
			return (1);
		}
	}
	if (x == 2)
	{
		pthread_mutex_lock(&args->death);
		if (args->philo[i].state_eating != 1)
		{
			args->is_anyone_dead = 1;
			pthread_mutex_unlock(&args->death);
			pthread_mutex_unlock(&args->time);
			ft_send_msg("died\n", &args->philo[i]);
			pthread_mutex_unlock(&args->verify);
			return (1);
		}
	}
	return (0);
}

void	*ft_routine_pat(void *arg)
{
	t_args		*args;
	int			i;
	long long	time;

	args = (t_args *)arg;
	i = 0;
	while (1)
	{
		if (pat_verify(args, i, 1) == 1)
			break ;
		if (i == args->n_philo)
			i = 0;
		pthread_mutex_lock(&args->time);
		time = get_time();
		if ((time - args->philo[i].time_of_last_meal) >= args->ttdie)
		{
			if (pat_verify(args, i, 2) == 1)
				break ;
			pthread_mutex_unlock(&args->death);
		}
		pthread_mutex_unlock(&args->verify);
		pthread_mutex_unlock(&args->time);
		i++;
	}
	return (0);
}
