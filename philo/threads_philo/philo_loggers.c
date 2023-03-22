/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_loggers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:40:34 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/03/18 22:00:38 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_log_philo(t_philo *philo, int philo_id, t_philo_status cur_status)
{
	t_time_ms	current_time;

	pthread_mutex_lock(&(philo->logger_mutex));
	if (!ft_die_condition(&philo->ph[philo_id - 1]) && ft_should_stop_dinner(philo))
		return ;
	current_time = ft_get_elapsed_time(philo->dinner_start);
	printf("%ld %d %s\n", current_time, philo_id,
		philo->philo_actions[cur_status]);
	pthread_mutex_unlock(&(philo->logger_mutex));
}

void	ft_print_args(t_philo *philo)
{
	if (DEBUG == FALSE)
		return ;
	printf("nbr philos:%d\ntime_d:%d\ntime_eat:%d\ntime_sleep:%d\nnbr\
	_times_must_eat:%d\n----------------------------------------------\
	----------------------------------------------\n",
		philo->nbr_philos, philo->time_die, philo->time_eat,
		philo->time_sleep, philo->nbr_times_must_eat);
}
