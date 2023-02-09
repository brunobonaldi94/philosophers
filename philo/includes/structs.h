/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 21:06:03 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/02/08 22:53:37 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_philosophers
{
	pthread_t		t;
	size_t			id;
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
	pthread_mutex_t	forks_mutex;
}	t_philo;

#endif