/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:23:54 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/03/13 20:44:14 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_bool	ft_log_eating(t_philo *philo, int philo_id)
{
	if (ft_should_stop_dinner(philo)
		|| ft_get_elapsed_time(philo->ph[philo_id - 1].last_meal_time)
		>= (t_time_ms)philo->ph[philo_id - 1].time_die)
		return (FALSE);
	ft_log_philo(philo, philo_id, FORK);
	ft_log_philo(philo, philo_id, FORK);
	ft_log_philo(philo, philo_id, EATING);
	if (philo->time_eat > philo->time_die)
	{
		ft_usleep(philo->time_die);
		ft_stop_dinner(philo, TRUE);
		return (FALSE);
	}
	return (TRUE);
}

void	ft_assign_forks(int nbr_philos, int philo_id, int forks[2])
{
	if (philo_id == nbr_philos)
	{
		forks[0] = philo_id - 1;
		forks[1] = 0;
	}
	else
	{
		forks[0] = philo_id - 1;
		forks[1] = philo_id;
	}
}

void	set_meal_time(t_philo *philo, int philo_id)
{
	philo->ph[philo_id -1].last_meal_time = ft_get_time_ms();
}

void	ft_adjust_nbr_times_must_eat(t_philo *philo, int philo_id)
{
	philo->ph[philo_id -1].nbr_times_must_eat--;
}

void	ft_get_fork(t_philo *philo, int philo_id)
{
	int	forks[2];

	if (ft_should_stop_dinner(philo))
		return ;
	ft_assign_forks(philo->nbr_philos, philo_id, forks);
	pthread_mutex_lock(&philo->ph[forks[0]].forks_mutex);
	pthread_mutex_lock(&philo->ph[forks[1]].forks_mutex);
	pthread_mutex_lock(&philo->ph[philo_id -1].last_meal_mutex);
	ft_adjust_nbr_times_must_eat(philo, philo_id);
	if (!ft_log_eating(philo, philo_id))
	{
		pthread_mutex_unlock(&philo->ph[forks[0]].forks_mutex);
		pthread_mutex_unlock(&philo->ph[forks[1]].forks_mutex);
		pthread_mutex_unlock(&philo->ph[philo_id -1].last_meal_mutex);
		ft_stop_dinner(philo, TRUE);
		return ;
	}
	set_meal_time(philo, philo_id);
	pthread_mutex_unlock(&philo->ph[philo_id -1].last_meal_mutex);
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
