/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:52:19 by brolivei          #+#    #+#             */
/*   Updated: 2023/06/13 09:33:44 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_message(char *msg, t_philo *p)
{
	long long	time;

	pthread_mutex_lock(&p->args->mutex);
	if (p->args->morreu >= 1 || p->args->todos_comeram == p->args->n_philo)
	{
		pthread_mutex_unlock(&p->args->mutex);
		return ;
	}
	pthread_mutex_unlock(&p->args->mutex);
	time = get_time() - p->args->start_time;
	pthread_mutex_lock(&p->args->printMutex);
	printf("%lld %d %s", time, p->n, msg);
	pthread_mutex_unlock(&p->args->mutex);
	return ;
}
