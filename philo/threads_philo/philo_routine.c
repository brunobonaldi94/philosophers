/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:23:54 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/03/08 23:08:01 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_log_eating(t_philo *philo, int philo_id)
{
	ft_log_philo(philo, philo_id, FORK);
	ft_log_philo(philo, philo_id, FORK);
	ft_log_philo(philo, philo_id, EATING);
}

void	ft_get_fork(t_philo *philo, int philo_id)
{
	int	fork_one;
	int	fork_two;

	if (philo_id == philo->nbr_philos)
	{
		fork_one = philo_id - 1;
		fork_two = 0;
	}
	else 
	{
		fork_one = philo_id - 1;
		fork_two = philo_id;
	}
	pthread_mutex_lock(&philo->ph[fork_one].forks_mutex);
	pthread_mutex_lock(&philo->ph[fork_two].forks_mutex);
	philo->ph[philo_id -1].last_meal_time = ft_get_time_ms(); 
	philo->ph[philo_id -1].nbr_times_must_eat--;
	ft_log_eating(philo, philo_id);
	ft_usleep(philo->ph[philo_id - 1].time_eat);
	pthread_mutex_unlock(&philo->ph[fork_one].forks_mutex);
	pthread_mutex_unlock(&philo->ph[fork_two].forks_mutex);
}

void	ft_eat_routine(t_philo *philo, int philo_id)
{

	if (philo->nbr_forks == 1)
		ft_log_philo(philo, philo_id, FORK);
	else
		ft_get_fork(philo, philo_id);
}

void	ft_sleep_routine(t_philo *philo, int philo_id)
{
	if (philo->ph[philo_id - 1].should_stop_dinner)
		return ;
	ft_usleep(philo->ph[philo_id - 1].time_sleep);
	ft_log_philo(philo, philo_id, SLEEPING);
	return ;
}

void	ft_think_routine()
{
	return ;
}