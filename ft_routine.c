/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:53:36 by brolivei          #+#    #+#             */
/*   Updated: 2023/07/03 15:23:27 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	verify_and_change(t_philo *filo, int x)
{
	pthread_mutex_lock(&filo->args->verify);
	if (x == 3 && filo->args->finish == 1)
	{
		pthread_mutex_unlock(&filo->args->verify);
		return (1);
	}
	if (x == 2)
	{
		if (filo->args->max_meals != -1
			&& filo->meals_count >= filo->args->max_meals)
		{
			filo->args->n_filo_done++;
			pthread_mutex_unlock(&filo->args->verify);
			return (1);
		}
	}
	if (filo->args->is_anyone_dead == 1 && (x == 0 || x == 1))
	{
		ft_reduce_lines(filo, x);
		return (1);
	}
	pthread_mutex_unlock(&filo->args->verify);
	return (0);
}

int	ft_pickup_forks(t_philo *filo)
{
	if (filo->args->n_philo == 1)
		ft_only_one(filo);
	else if (filo->n % 2)
	{
		return (ft_reduce_lines2(filo));
	}
	else
	{
		pthread_mutex_lock(filo->l_fork);
		if (verify_and_change(filo, 0) == 1)
		{
			pthread_mutex_unlock(filo->l_fork);
			return (0);
		}
		ft_send_msg("has taken a fork\n", filo);
		pthread_mutex_lock(filo->r_fork);
		if (verify_and_change(filo, 0) == 1)
		{
			ft_put_down_the_forks(filo);
			return (0);
		}
		ft_send_msg("has taken a fork\n", filo);
		return (1);
	}
	return (0);
}

void	ft_put_down_the_forks(t_philo *filo)
{
	pthread_mutex_unlock(filo->l_fork);
	if (filo->args->n_philo != 1)
		pthread_mutex_unlock(filo->r_fork);
}

void	sleep_to_think(t_philo *filo)
{
	filo->state_sleeping = 0;
	filo->state_thinking = 1;
	if (verify_and_change(filo, 0) == 1)
		return ;
	ft_send_msg("is thinking\n", filo);
}

void	*ft_routine(void *arg)
{
	t_philo	*filo;

	filo = (t_philo *)arg;
	while (verify_and_change(filo, 3) != 1)
	{
		if (verify_and_change(filo, 0) == 1)
			break ;
		if (filo->state_thinking == 1)
		{
			if (verify_and_change(filo, 0) == 1)
				break ;
			if (ft_pickup_forks(filo) == 1)
			{
				if (ft_after_pick_forks(filo) == -1)
					break ;
			}
		}
		if (filo->state_sleeping == 1)
			sleep_to_think(filo);
		usleep(1000);
	}
	return (NULL);
}
