/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_mutex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 21:18:25 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/02/27 21:18:34 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_init_mutex(t_philo *philo)
{
	size_t	index;

	index = 0;
	while (index < philo->nbr_philos)
	{
		pthread_mutex_init(&philo->ph[index].forks_mutex, NULL);
		index++;
	}
}

void	ft_destroy_mutex(t_philo *philo)
{
	size_t	index;

	index = 0;
	while (index < philo->nbr_philos)
	{
		pthread_mutex_destroy(&philo->ph[index].forks_mutex);
		index++;
	}
}