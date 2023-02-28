/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 21:06:03 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/02/27 22:34:04 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct timeval t_timeval;
typedef time_t	t_time_ms;
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
	size_t			id;
	int				fork[2];
	size_t			time_die;
	size_t			time_eat;
	size_t			time_sleep;
	size_t			nbr_times_must_eat;
	t_philo_status	cur_status;
	pthread_mutex_t	forks_mutex;
}	t_philosophers;

typedef struct s_philo
{
	size_t			nbr_philos;
	size_t			nbr_forks;
	size_t			time_die;
	size_t			time_eat;
	size_t			time_sleep;
	size_t			nbr_times_must_eat;
	t_philosophers	*ph;
	t_time_ms		dinning_start;
	char			**philo_actions;
}	t_philo;

typedef	struct s_philo_id
{
	t_philo			*philo;
	size_t			id;
}	t_philo_id;

#endif