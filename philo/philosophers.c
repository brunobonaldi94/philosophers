/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 01:46:44 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/03/06 22:57:20 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
number_of_philosophers time_to_die time_to_eat time_to_sleep
[number_of_times_each_philosopher_must_eat]
*/


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

void	ft_load_args(t_philo *philos, char *argv[], t_bool has_five_args)
{
	philos->nbr_philos = ft_atoi(argv[1]);
	philos->nbr_forks = philos->nbr_philos;
	philos->time_die = ft_atoi(argv[2]);
	philos->time_eat = ft_atoi(argv[3]);
	philos->time_sleep = ft_atoi(argv[4]);
	if (has_five_args)
		philos->nbr_times_must_eat = ft_atoi(argv[5]);
	ft_assign_philo_actions(philos);
}

int	main(int argc, char *argv[])
{
	t_philo	philos;

	if (!ft_has_valid_args(argc, argv))
		return (ERROR_CODE);
	ft_load_args(&philos, argv, argc == ARG_NUMBER_OF_TIMES_MUST_EAT);
	ft_create_philosophers(&philos, philos.nbr_philos);
	ft_free_philosophers(&philos);
	return (SUCCESS_CODE);
}