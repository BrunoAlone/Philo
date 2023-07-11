/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_them_alive.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:29:02 by brolivei          #+#    #+#             */
/*   Updated: 2023/06/30 11:41:02 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_create_forks_and_other(t_args *args)
{
	int	i;

	i = 0;
	args->garfo = malloc(sizeof(pthread_mutex_t) * args->n_philo);
	while (i < args->n_philo)
	{
		pthread_mutex_init(&args->garfo[i], NULL);
		i++;
	}
	pthread_mutex_init(&args->msg, NULL);
	pthread_mutex_init(&args->death, NULL);
	pthread_mutex_init(&args->time, NULL);
	pthread_mutex_init(&args->verify, NULL);
}

void	ft_let_them_born(t_args *args)
{
	int	i;

	i = 0;
	while (i < args->n_philo)
	{
		if (pthread_create(&args->philo[i].thread, NULL, &ft_routine,
				&args->philo[i]) != 0)
			printf("Error creating threads\n");
		i++;
	}
	if (i > 1)
	{
		if (pthread_create(&args->patologista, NULL,
				&ft_routine_pat, args) != 0)
			printf("Error creating threads\n");
	}
	i = 0;
	while (i < args->n_philo)
	{
		if (pthread_join(args->philo[i].thread, NULL) != 0)
			printf("Error joining threads\n");
		i++;
	}
	if (i > 1)
		pthread_join(args->patologista, NULL);
}

void	ft_make_them_alive(t_args *args)
{
	int	i;

	i = 0;
	ft_create_forks_and_other(args);
	while (i < args->n_philo)
	{
		args->philo[i].n = i + 1;
		args->philo[i].time_of_last_meal = get_time();
		args->philo[i].meals_count = 0;
		args->philo[i].l_fork = &args->garfo[i];
		if (args->n_philo != 1)
			args->philo[i].r_fork = &args->garfo[(i + 1) % args->n_philo];
		args->philo[i].args = args;
		args->philo[i].state_dead = 0;
		args->philo[i].state_eating = 0;
		args->philo[i].state_sleeping = 0;
		args->philo[i].state_thinking = 1;
		i++;
	}
	ft_let_them_born(args);
}
