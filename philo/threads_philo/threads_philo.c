/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 21:51:19 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/03/15 23:10:55 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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

void	*ft_routine(void *philo)
{
	t_cur_philo	*p;

	p = (t_cur_philo *)philo;
	while (!ft_should_stop_dinner(p->philo))
	{
		if (p->cur_philo->id % 2)
		{
			ft_eat_routine(p->philo, p->cur_philo->id);
			ft_sleep_routine(p->philo, p->cur_philo->id);
			ft_think_routine(p->philo, p->cur_philo->id);
		}
		else
		{
			ft_think_routine(p->philo, p->cur_philo->id);
			ft_eat_routine(p->philo, p->cur_philo->id);
			ft_sleep_routine(p->philo, p->cur_philo->id);
		}
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
	while (index < philo->nbr_philos)
	{
		printf("philo %d - fork0=>%d fork1=>%d\n", philo->ph[index].id, philo->ph[index].forks[0], philo->ph[index].forks[1]);
		index++;
	}

}

t_bool	ft_init_philosophers(t_philo *philo, size_t nbr_philos)
{
	size_t		index;
	t_cur_philo	*cur_philo;

	index = 0;
	philo->dinner_start = ft_get_time_ms();
	philo->should_stop_dinner = FALSE;
	ft_assign_philo_timers(philo);
	ft_assign_all_forks(philo);
	if (nbr_philos == 1)
	{
		if (pthread_create(&philo->ph[index].ph_thread, NULL,
				ft_routine_only_one_philo, philo) != 0)
			return (FALSE);
		return (TRUE);
	}
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
