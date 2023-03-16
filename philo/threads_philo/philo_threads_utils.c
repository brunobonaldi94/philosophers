/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:34:38 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/03/16 19:43:13 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_assign_forks(int nbr_philos, int philo_id, int forks[2])
{
	if (philo_id == nbr_philos)
	{
		forks[0] = 0;
		forks[1] = philo_id - 1;
	}
	else
	{
		forks[0] = philo_id - 1;
		forks[1] = philo_id;
	}
}

void	ft_assign_all_forks(t_philo *philo)
{
	int	index;

	index = 0;
	while (index < philo->nbr_philos)
	{
		ft_assign_forks(philo->nbr_philos, philo->ph[index].id,
			philo->ph[index].forks);
		index++;
	}
	index = 0;
}

void	ft_assign_philo_actions(t_philo *philo)
{
	philo->philo_actions = (char **)malloc(sizeof(char *) * (NBR_ACTIONS + 1));
	philo->philo_actions[EATING] = ft_strdup("is eating");
	philo->philo_actions[THINKING] = ft_strdup("is thinking");
	philo->philo_actions[SLEEPING] = ft_strdup("is sleeping");
	philo->philo_actions[DIED] = ft_strdup("died");
	philo->philo_actions[FORK] = ft_strdup("has taken a fork");
	philo->philo_actions[NBR_ACTIONS] = NULL;
}

void	ft_assign_philo_timers(t_philo *philo)
{
	int	index;

	index = 0;
	while (index < philo->nbr_philos)
	{
		philo->ph[index].id = index + 1;
		philo->ph[index].time_die = philo->time_die;
		philo->ph[index].time_eat = philo->time_eat;
		philo->ph[index].time_sleep = philo->time_sleep;
		philo->ph[index].nbr_times_must_eat = philo->nbr_times_must_eat;
		index++;
	}
}

t_bool	ft_launch_philo_threads(t_philo *philo, size_t nbr_philos)
{
	size_t		index;
	t_cur_philo	*cur_philo;

	index = 0;
	while (index < nbr_philos)
	{
		cur_philo = (t_cur_philo *)malloc(sizeof(t_cur_philo));
		cur_philo->philo = philo;
		philo->ph[index].last_meal_time = ft_get_time_ms();
		cur_philo->cur_philo = &philo->ph[index];
		if (pthread_create(&philo->ph[index].ph_thread, NULL,
				ft_routine, cur_philo) != 0)
			return (FALSE);
		index++;
	}
	return (TRUE);
}
