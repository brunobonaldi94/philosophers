/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_watcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 21:19:27 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/03/08 23:11:35 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_bool	ft_check_last_meal(t_philo *philo)
{
	int	index;
	t_philosophers	*cur_ph;

	index = 0;
	while (TRUE)
	{
		cur_ph = &philo->ph[index];
		if (cur_ph->last_meal_time != 0 && ft_get_elapsed_time(cur_ph->last_meal_time) >= (t_time_ms)cur_ph->time_die)
		{
			pthread_mutex_lock(&cur_ph->stop_dinner_mutex);
			cur_ph->should_stop_dinner = TRUE;
			ft_log_philo(philo, cur_ph->id, DIED);
			pthread_mutex_unlock(&cur_ph->stop_dinner_mutex);
			return (FALSE);
		}
		index++;
		if (index == philo->nbr_philos - 1)
			index = 0;
	}
}

void	*ft_watcher_routine(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	ft_check_last_meal(p);
	return (philo);
}

t_bool	ft_init_watcher(t_philo *philo)
{
	if (pthread_create(&philo->p_watcher, NULL,
			ft_watcher_routine, philo) != 0)
			return (FALSE);
	return (TRUE);
}
