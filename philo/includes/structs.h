/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 21:06:03 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/03/13 23:07:01 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct timeval	t_timeval;
typedef time_t			t_time_ms;
typedef enum e_philo_status
{
	EATING,
	THINKING,
	SLEEPING,
	DIED,
	FORK,
}	t_philo_status;

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_philosophers
{
	pthread_t		ph_thread;
	int				id;
	int				forks[2];
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				nbr_times_must_eat;
	t_time_ms		last_meal_time;
	t_philo_status	cur_status;
	pthread_mutex_t	forks_mutex;
	pthread_mutex_t	last_meal_mutex;
}	t_philosophers;

typedef struct s_philo
{
	int				nbr_philos;
	int				nbr_forks;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				nbr_times_must_eat;
	t_philosophers	*ph;
	t_time_ms		dinner_start;
	pthread_mutex_t	logger_mutex;
	pthread_mutex_t	stop_dinner_mutex;
	t_bool			should_stop_dinner;
	pthread_t		p_watcher;
	char			**philo_actions;
}	t_philo;

typedef struct s_cur_philo
{
	t_philo			*philo;
	t_philosophers	*cur_philo;
}	t_cur_philo;

#endif
