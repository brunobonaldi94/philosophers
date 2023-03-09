/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_mutex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 21:18:25 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/03/08 23:05:07 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_init_mutex(t_philo *philo)
{
	int	index;

	index = 0;
	pthread_mutex_init(&philo->logger_mutex, NULL);
	while (index < philo->nbr_philos)
	{
		pthread_mutex_init(&philo->ph[index].stop_dinner_mutex, NULL);
		pthread_mutex_init(&philo->ph[index].forks_mutex, NULL);
		index++;
	}
}

void	ft_destroy_mutex(t_philo *philo)
{
	int	index;

	index = 0;
	pthread_mutex_destroy(&philo->logger_mutex);
	while (index < philo->nbr_philos)
	{
		pthread_mutex_destroy(&philo->ph[index].stop_dinner_mutex);
		pthread_mutex_destroy(&philo->ph[index].forks_mutex);
		index++;
	}
}