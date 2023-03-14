/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:23:54 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/03/14 18:13:17 by bbonaldi         ###   ########.fr       */
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
	{
		printf("morreu aqui\n");
		return (FALSE);
	}
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

void	ft_get_fork(t_philo *philo, int philo_id)
{
	int	forks[2];

	forks[0] = philo->ph[philo_id - 1].forks[0];
	forks[1] = philo->ph[philo_id - 1].forks[1];
	if (ft_should_stop_dinner(philo))
		return ;
	pthread_mutex_lock(&philo->ph[forks[0]].forks_mutex);
	pthread_mutex_lock(&philo->ph[forks[1]].forks_mutex);
	if (!ft_log_eating(philo, philo_id))
	{
		pthread_mutex_unlock(&philo->ph[forks[0]].forks_mutex);
		pthread_mutex_unlock(&philo->ph[forks[1]].forks_mutex);
		ft_stop_dinner(philo, TRUE);
		return ;
	}
	ft_usleep(philo->ph[philo_id - 1].time_eat);
	pthread_mutex_unlock(&philo->ph[forks[0]].forks_mutex);
	pthread_mutex_unlock(&philo->ph[forks[1]].forks_mutex);
}

void	ft_eat_routine(t_philo *philo, int philo_id)
{
	if (ft_should_stop_dinner(philo))
		return ;
	if (philo->nbr_forks == 1)
		ft_log_philo(philo, philo_id, FORK);
	else
		ft_get_fork(philo, philo_id);
}

void	ft_sleep_routine(t_philo *philo, int philo_id)
{
	if (ft_should_stop_dinner(philo) || ft_should_die(philo, philo_id))
		return ;
	ft_log_philo(philo, philo_id, SLEEPING);
	ft_usleep(philo->ph[philo_id - 1].time_sleep);
	return ;
}

void	ft_think_routine(t_philo *philo, int philo_id)
{
	if (ft_should_stop_dinner(philo))
		return ;
	ft_log_philo(philo, philo_id, THINKING);
}
