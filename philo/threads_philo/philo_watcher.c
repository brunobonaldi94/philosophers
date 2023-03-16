/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_watcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 21:19:27 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/03/16 19:48:24 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_bool	ft_should_end_dinner(t_philo *philo)
{
	t_bool	should_die;
	t_bool	eaten_x_times;

	should_die = ft_should_any_philo_die(philo);
	eaten_x_times = ft_check_all_philosophers_eaten_x_times(philo);
	return (should_die || eaten_x_times || ft_should_stop_dinner(philo));
}

t_bool	ft_watch_philo(t_philo *philo)
{
	while (TRUE)
	{
		if (ft_should_end_dinner(philo))
		{
			ft_stop_dinner(philo, TRUE);
			return (FALSE);
		}
	}
	return (TRUE);
}

void	*ft_watcher_routine(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	ft_watch_philo(p);
	return (philo);
}

t_bool	ft_init_watcher(t_philo *philo)
{
	if (philo->nbr_philos == 1)
		return (FALSE);
	if (pthread_create(&philo->p_watcher, NULL,
			ft_watcher_routine, philo) != 0)
		return (FALSE);
	return (TRUE);
}
