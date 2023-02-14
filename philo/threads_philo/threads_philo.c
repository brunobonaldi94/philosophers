/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 21:51:19 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/02/13 23:18:03 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_routine(void *philo)
{
	t_philo_id	philo_id;

	philo_id = *(t_philo_id *)philo;
	pthread_mutex_lock(&philo_id.philo->forks_mutex);
	printf("philo %ld\n", philo_id.id);
	pthread_mutex_unlock(&philo_id.philo->forks_mutex);
	free(philo);
	return (NULL);
}

void	*ft_routine_lonely_philo(void *philo)
{

}

t_bool	ft_init_philosophers(t_philo *philo, size_t nbr_philos)
{
	size_t		index;
	t_philo_id	*philo_id; 

	index = 0;
	if (nbr_philos == 1)
	{
		if (pthread_create(&philo->ph[index].t, NULL,
				ft_routine_lonely_philo, philo) != 0)
	}
	while (index < nbr_philos)
	{
		philo_id = (t_philo_id *)malloc(sizeof(t_philo_id));
		philo_id->philo = philo;
		philo->ph[index].id = index;
		philo_id->id = index;
		if (pthread_create(&philo->ph[index].t, NULL,
				ft_routine, philo_id) != 0)
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