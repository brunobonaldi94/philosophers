/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_loggers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:40:34 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/02/27 23:11:37 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_log_philo(t_philo *philo, int philo_id, t_philo_status cur_status)
{
	t_time_ms	current_time;

	current_time = ft_get_elapsed_time(philo->dinning_start);
	printf("%ld\n", current_time);
	printf("%ld philosopher %d %s\n", current_time, philo_id,
		philo->philo_actions[cur_status]);
}