/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:56:50 by brolivei          #+#    #+#             */
/*   Updated: 2023/06/29 13:00:02 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_for_non_digits(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i <= argc - 1)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_is_digit(argv[i][j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_check_even_more(t_args **args)
{
	if ((*args)->n_philo <= 0
		|| ((*args)->max_meals <= 0 && (*args)->max_meals != -1))
	{
		free((*args)->philo);
		free(*args);
		*args = NULL;
	}
	else if ((*args)->ttdie <= 0 || (*args)->tteat <= 0 || (*args)->ttsleep < 0)
	{
		free((*args)->philo);
		free(*args);
		*args = NULL;
	}
}

t_args	*collect_and_check_args(int argc, char **argv)
{
	t_args	*args;

	args = malloc(sizeof(t_args));
	if (check_for_non_digits(argc, argv) == 0)
	{
		free(args);
		return (NULL);
	}
	args->n_philo = ft_atoi(argv[1]);
	args->ttdie = ft_atoi(argv[2]);
	args->tteat = ft_atoi(argv[3]);
	args->ttsleep = ft_atoi(argv[4]);
	if (argc == 6)
		args->max_meals = ft_atoi(argv[5]);
	else
		args->max_meals = -1;
	args->start_time = get_time();
	args->finish = 0;
	args->n_filo_done = 0;
	args->is_anyone_dead = 0;
	args->philo = malloc(sizeof(t_philo) * args->n_philo);
	ft_check_even_more(&args);
	return (args);
}
