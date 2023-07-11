/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_msg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:09:51 by brolivei          #+#    #+#             */
/*   Updated: 2023/06/29 16:11:55 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_send_msg(char *msg, t_philo *filo)
{
	long long	time;

	pthread_mutex_lock(&filo->args->time);
	time = get_time() - filo->args->start_time;
	pthread_mutex_unlock(&filo->args->time);
	pthread_mutex_lock(&filo->args->msg);
	printf("%lld %d %s", time, filo->n, msg);
	pthread_mutex_unlock(&filo->args->msg);
}
