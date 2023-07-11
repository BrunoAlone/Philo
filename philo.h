/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 09:00:41 by brolivei          #+#    #+#             */
/*   Updated: 2023/06/30 11:35:31 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct philo
{
	int				n;
	int				meals_count;
	int				state_thinking;
	int				state_eating;
	int				state_sleeping;
	int				state_dead;
	pthread_t		thread;
	long long		time_of_last_meal;
	struct args		*args;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}				t_philo;

typedef struct args
{
	int				n_philo;
	int				ttdie;
	int				tteat;
	int				ttsleep;
	int				max_meals;
	int				finish;
	int				n_filo_done;
	int				is_anyone_dead;
	long long		start_time;
	t_philo			*philo;
	pthread_t		patologista;
	pthread_mutex_t	*garfo;
	pthread_mutex_t	msg;
	pthread_mutex_t	death;
	pthread_mutex_t	time;
	pthread_mutex_t	verify;
}				t_args;

/*Utils*/

int			ft_atoi(const char *nptr);
long long	get_time(void);
int			ft_is_digit(int c);

/*Core*/
t_args		*collect_and_check_args(int argc, char **argv);
void		ft_make_them_alive(t_args *args);
void		ft_clean_mutex(t_args **args);
void		*ft_routine(void *arg);
void		ft_send_msg(char *msg, t_philo *filo);
void		*ft_routine_pat(void *arg);
void		ft_put_down_the_forks(t_philo *filo);
int			verify_and_change(t_philo *filo, int x);
int			ft_after_pick_forks(t_philo *filo);
void		ft_only_one(t_philo *filo);
void		ft_reduce_lines(t_philo *filo, int x);
int			ft_reduce_lines2(t_philo *filo);

#endif
