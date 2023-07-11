/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reduce_lines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 11:26:40 by brolivei          #+#    #+#             */
/*   Updated: 2023/07/03 15:33:09 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_reduce_lines(t_philo *filo, int x)
{
	filo->args->finish = 1;
	if (x == 1)
		ft_put_down_the_forks(filo);
	pthread_mutex_unlock(&filo->args->verify);
}

int	ft_reduce_lines2(t_philo *filo)
{
	pthread_mutex_lock(filo->r_fork);
	
	if (verify_and_change(filo, 0) == 1)
	{
		pthread_mutex_unlock(filo->r_fork);
		return (0);
	}
	ft_send_msg("has taken a fork\n", filo);
	pthread_mutex_lock(filo->l_fork);
	if (verify_and_change(filo, 0) == 1)
	{
		ft_put_down_the_forks(filo);
		return (0);
	}
	ft_send_msg("has taken a fork\n", filo);
	return (1);
}
