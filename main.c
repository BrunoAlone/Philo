/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei <brolivei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:55:04 by brolivei          #+#    #+#             */
/*   Updated: 2023/06/27 20:58:01 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_args	*args;

	if (argc != 5 && argc != 6)
		return (-1);
	args = collect_and_check_args(argc, argv);
	if (args == NULL)
	{
		printf("Error collecting args \n");
		return (0);
	}
	ft_make_them_alive(args);
	ft_clean_mutex(&args);
	free(args->philo);
	free(args->garfo);
	free(args);
	return (0);
}
