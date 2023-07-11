/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_mutex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:49:18 by brolivei          #+#    #+#             */
/*   Updated: 2023/06/28 15:18:50 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_clean_mutex(t_args **args)
{
	int	i;

	i = 0;
	while (i < (*args)->n_philo)
	{
		pthread_mutex_destroy(&(*args)->garfo[i]);
		i++;
	}
	pthread_mutex_destroy(&(*args)->msg);
	pthread_mutex_destroy(&(*args)->death);
	pthread_mutex_destroy(&(*args)->time);
	pthread_mutex_destroy(&(*args)->verify);
}
