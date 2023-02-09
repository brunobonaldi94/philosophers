/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 21:51:19 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/02/08 23:02:03 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_routine(void *philo)
{
	t_philosophers	phil;

	phil = *(t_philosophers *)philo;
	printf("philo %ld\n", phil.id);
	return (NULL);
}

t_bool	ft_init_philosophers(t_philo *philo, size_t nbr_philos)
{
	size_t	index;

	index = 0;
	while (index < nbr_philos)
	{
		philo->ph[index].id = index;
		if (pthread_create(&philo->ph[index].t, NULL,
				ft_routine, &philo->ph[index]) != 0)
			return (FALSE);
		index++;
	}
	return (TRUE);
}

t_bool	ft_join_philosophers(t_philo *philo, size_t nbr_philos)
{
	size_t	index;

	index = 0;
	while (index < nbr_philos)
	{
		if (pthread_join(philo->ph[index].t, NULL) != 0)
			return (FALSE);
		index++;
	}
	return (TRUE);
}

void	ft_create_philosophers(t_philo *philo, size_t nbr_philos)
{
	philo->ph = (t_philosophers *)malloc(sizeof(t_philosophers) * nbr_philos);
	pthread_mutex_init(&philo->forks_mutex, NULL);
	if (!ft_init_philosophers(philo, nbr_philos))
		return ;
	if (!ft_join_philosophers(philo, nbr_philos))
		return ;
	pthread_mutex_destroy(&philo->forks_mutex);
}