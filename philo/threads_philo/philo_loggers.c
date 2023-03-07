/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_loggers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:40:34 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/03/06 22:50:34 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_log_philo(t_philo *philo, int philo_id, t_philo_status cur_status)
{
	t_time_ms	current_time;

	pthread_mutex_lock(&(philo->logger_mutex));
	current_time = ft_get_elapsed_time(philo->dinning_start);
	printf("%ld %d %s\n", current_time, philo_id,
		philo->philo_actions[cur_status]);
	pthread_mutex_unlock(&(philo->logger_mutex));
}