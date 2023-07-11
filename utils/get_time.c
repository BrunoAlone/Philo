/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:17:46 by brolivei          #+#    #+#             */
/*   Updated: 2023/06/30 11:42:51 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long long	get_time(void)
{
	struct timeval	time;
	long long		x;

	gettimeofday(&time, NULL);
	x = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (x);
}
