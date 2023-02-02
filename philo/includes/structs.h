/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 21:06:03 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/02/01 22:30:19 by bbonaldi         ###   ########.fr       */
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
	pthread_t		philosophers;
	int				fork;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	pthread_mutex_t	*mutex_philo;
}	t_philosophers;

typedef struct s_philo
{
	size_t	nbr_philos;
	size_t	time_die;
	size_t	time_eat;
	size_t	time_sleep;
	size_t	nbr_times_must_eat;
}	t_philo;

#endif