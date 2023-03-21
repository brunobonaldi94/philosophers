/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:23:54 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/03/20 21:29:35 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	set_meal_time(t_philo *philo, int philo_id)
{
	pthread_mutex_lock(&philo->ph[philo_id -1].last_meal_mutex);
	philo->ph[philo_id -1].last_meal_time = ft_get_time_ms();
	pthread_mutex_unlock(&philo->ph[philo_id -1].last_meal_mutex);
}

void	ft_adjust_nbr_times_must_eat(t_philo *philo, int philo_id)
{
	pthread_mutex_lock(&philo->ph[philo_id -1].eaten_time_mutex);
	philo->ph[philo_id -1].nbr_times_must_eat--;
	pthread_mutex_unlock(&philo->ph[philo_id -1].eaten_time_mutex);
}

t_bool	ft_log_eating(t_philo *philo, int philo_id)
{
	if (ft_should_stop_dinner(philo))
		return (FALSE);
	ft_log_philo(philo, philo_id, FORK);
	ft_log_philo(philo, philo_id, FORK);
	ft_log_philo(philo, philo_id, EATING);
	set_meal_time(philo, philo_id);
	ft_adjust_nbr_times_must_eat(philo, philo_id);
	if (philo->time_eat > philo->time_die)
	{
		ft_usleep(philo->time_die);
		ft_stop_dinner(philo, TRUE);
		return (FALSE);
	}
	return (TRUE);
}
