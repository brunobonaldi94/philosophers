/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_watcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 21:19:27 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/03/13 19:54:27 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_bool	ft_check_all_philosophers_eaten_x_times(t_philo *philo)
{
	int	index;

	index = 0;
	while (index < philo->nbr_philos)
	{
		if (philo->ph[index].nbr_times_must_eat > 0
			|| philo->ph[index].nbr_times_must_eat == -1)
			return (FALSE);
		index++;
	}
	return (TRUE);
}

t_bool	ft_should_die(t_philo *philo, int philo_id)
{
	t_bool			should_die;
	t_philosophers	*cur_ph;

	cur_ph = &philo->ph[philo_id -1];
	pthread_mutex_lock(&cur_ph->last_meal_mutex);
	should_die = (ft_get_elapsed_time(cur_ph->last_meal_time)
			>= (t_time_ms)cur_ph->time_die);
	if (should_die)
		ft_log_philo(philo, cur_ph->id, DIED);
	pthread_mutex_unlock(&cur_ph->last_meal_mutex);
	return (should_die);
}

t_bool	ft_should_any_philo_die(t_philo *philo)
{
	int	index;

	index = 0;
	while (index < philo->nbr_philos)
	{
		if (ft_should_die(philo, philo->ph[index].id))
			return (TRUE);
		index++;
	}
	return (FALSE);
}

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
