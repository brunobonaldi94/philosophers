/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 21:51:19 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/03/20 21:39:40 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_routine(void *philo)
{
	t_cur_philo	*p;

	p = (t_cur_philo *)philo;
	if (p->cur_philo->id % 2)
		usleep(500);
	while (!ft_should_stop_dinner(p->philo))
	{
		ft_eat_routine(p->philo, p->cur_philo->id);
		ft_sleep_routine(p->philo, p->cur_philo->id);
		ft_think_routine(p->philo, p->cur_philo->id);
	}
	free(philo);
	return (NULL);
}

void	*ft_routine_only_one_philo(void *philo)
{
	t_philo	*p;
	int		philo_id;

	p = (t_philo *)philo;
	philo_id = 1;
	ft_eat_routine(p, philo_id);
	ft_usleep(p->ph[philo_id - 1].time_die);
	ft_log_philo(p, philo_id, DIED);
	return (NULL);
}

t_bool	ft_init_philosophers(t_philo *philo, size_t nbr_philos)
{
	philo->dinner_start = ft_get_time_ms();
	philo->should_stop_dinner = FALSE;
	ft_assign_philo_timers(philo);
	ft_assign_all_forks(philo);
	if (nbr_philos == 1)
	{
		if (pthread_create(&philo->ph[0].ph_thread, NULL,
				ft_routine_only_one_philo, philo) != 0)
			return (FALSE);
		return (TRUE);
	}
	return (ft_launch_philo_threads(philo, nbr_philos));
}

t_bool	ft_join_philosophers(t_philo *philo, size_t nbr_philos)
{
	size_t	index;

	index = 0;
	while (index < nbr_philos)
	{
		if (pthread_join(philo->ph[index].ph_thread, NULL) != 0)
			return (FALSE);
		index++;
	}
	if (nbr_philos > 1 && pthread_join(philo->p_watcher, NULL) != 0)
		return (FALSE);
	return (TRUE);
}

void	ft_create_philosophers(t_philo *philo, size_t nbr_philos)
{
	ft_assign_philo_actions(philo);
	philo->ph = (t_philosophers *)malloc(sizeof(t_philosophers) * nbr_philos);
	ft_init_mutex(philo);
	ft_init_philosophers(philo, nbr_philos);
	ft_init_watcher(philo);
	ft_join_philosophers(philo, nbr_philos);
	ft_destroy_mutex(philo);
}
