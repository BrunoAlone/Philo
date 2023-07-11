/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_after_pick_forks.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:07:24 by brolivei          #+#    #+#             */
/*   Updated: 2023/06/30 11:41:56 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_after_pick_forks(t_philo *filo)
{
	filo->state_thinking = 0;
	pthread_mutex_lock(&filo->args->death);
	filo->state_eating = 1;
	pthread_mutex_unlock(&filo->args->death);
	if (verify_and_change(filo, 1) == 1)
	{
		return (-1);
	}
	pthread_mutex_lock(&filo->args->time);
	filo->time_of_last_meal = get_time();
	pthread_mutex_unlock(&filo->args->time);
	ft_send_msg("is eating\n", filo);
	usleep((filo->args->tteat) * 1000);
	ft_put_down_the_forks(filo);
	filo->meals_count++;
	if (verify_and_change(filo, 2) == 1)
		return (-1);
	filo->state_eating = 0;
	filo->state_sleeping = 1;
	if (verify_and_change(filo, 0) == 1)
		return (-1);
	ft_send_msg("is sleeping\n", filo);
	usleep(filo->args->ttsleep * 1000);
	return (0);
}

void	ft_only_one(t_philo *filo)
{
	ft_send_msg("has taken a fork\n", filo);
	pthread_mutex_lock(&filo->args->death);
	usleep((filo->args->ttdie) * 1000);
	ft_send_msg("died\n", filo);
	filo->args->finish = 1;
	pthread_mutex_unlock(&filo->args->death);
	return ;
}
