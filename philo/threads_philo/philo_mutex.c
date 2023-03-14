/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_mutex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 21:18:25 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/03/14 17:53:12 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_init_mutex(t_philo *philo)
{
	int	index;

	index = 0;
	pthread_mutex_init(&philo->logger_mutex, NULL);
	pthread_mutex_init(&philo->stop_dinner_mutex, NULL);
	while (index < philo->nbr_philos)
	{
		pthread_mutex_init(&philo->ph[index].forks_mutex, NULL);
		pthread_mutex_init(&philo->ph[index].eaten_time_mutex, NULL);
		pthread_mutex_init(&philo->ph[index].last_meal_mutex, NULL);
		index++;
	}
}

void	ft_destroy_mutex(t_philo *philo)
{
	int	index;

	index = 0;
	pthread_mutex_destroy(&philo->logger_mutex);
	pthread_mutex_destroy(&philo->stop_dinner_mutex);
	while (index < philo->nbr_philos)
	{
		pthread_mutex_destroy(&philo->ph[index].forks_mutex);
		pthread_mutex_destroy(&philo->ph[index].eaten_time_mutex);
		pthread_mutex_destroy(&philo->ph[index].last_meal_mutex);
		index++;
	}
}

t_bool	ft_should_stop_dinner(t_philo *philo)
{
	t_bool	should_stop;

	pthread_mutex_lock(&philo->stop_dinner_mutex);
	should_stop = philo->should_stop_dinner;
	pthread_mutex_unlock(&philo->stop_dinner_mutex);
	return (should_stop);
}

void	ft_stop_dinner(t_philo *philo, t_bool should_stop_dinner)
{
	pthread_mutex_lock(&philo->stop_dinner_mutex);
	philo->should_stop_dinner = should_stop_dinner;
	pthread_mutex_unlock(&philo->stop_dinner_mutex);
}
