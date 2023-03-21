/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_watcher_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 21:19:27 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/03/20 21:17:42 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_bool	ft_check_all_philosophers_eaten_x_times(t_philo *philo)
{
	int	index;

	index = 0;
	while (index < philo->nbr_philos)
	{
		pthread_mutex_lock(&philo->ph[index].eaten_time_mutex);
		if (philo->ph[index].nbr_times_must_eat > 0
			|| philo->ph[index].nbr_times_must_eat == -1)
		{
			pthread_mutex_unlock(&philo->ph[index].eaten_time_mutex);
			return (FALSE);
		}
		pthread_mutex_unlock(&philo->ph[index].eaten_time_mutex);
		index++;
	}
	return (TRUE);
}

t_bool	ft_die_condition(t_philosophers	*cur_ph)
{
	return (ft_get_elapsed_time(cur_ph->last_meal_time)
		>= (t_time_ms)cur_ph->time_die);
}

t_bool	ft_should_die(t_philo *philo, int philo_id)
{
	t_bool			should_die;
	t_philosophers	*cur_ph;

	cur_ph = &philo->ph[philo_id -1];
	pthread_mutex_lock(&cur_ph->last_meal_mutex);
	should_die = ft_die_condition(cur_ph);
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
