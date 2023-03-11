/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 22:35:12 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/03/11 15:37:57 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_free_philo_actions(t_philo *philo)
{
	size_t	index;

	index = 0;
	while (philo->philo_actions[index])
		free(philo->philo_actions[index++]);
	free(philo->philo_actions);
}

void	ft_free_philosophers(t_philo *philo)
{
	free(philo->ph);
	ft_free_philo_actions(philo);
}
