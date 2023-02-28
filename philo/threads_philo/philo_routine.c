/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:23:54 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/02/27 23:13:23 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_eat_routine(t_philo *philo, int philo_id)
{

	pthread_mutex_lock(&philo->ph[philo_id].forks_mutex);
	if (philo->nbr_forks == 1)
		ft_log_philo(philo, philo_id + 1, FORK);
	pthread_mutex_unlock(&philo->ph[philo_id].forks_mutex);
}

void	ft_sleep_routine(t_philo *philo, int philo_id)
{
	usleep(philo->ph[philo_id].time_sleep);
	printf("%ld", philo->ph[philo_id].time_sleep);
	return ;
}

void	ft_think_routine()
{
	return ;
}