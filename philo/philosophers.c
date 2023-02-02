/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 01:46:44 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/02/01 22:31:38 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
number_of_philosophers time_to_die time_to_eat time_to_sleep
[number_of_times_each_philosopher_must_eat]
*/

void	ft_load_args(t_philo *philos, char *argv[], t_bool has_five_args)
{
	philos->nbr_philos = ft_atoi(argv[1]);
	philos->time_die = ft_atoi(argv[2]);
	philos->time_eat = ft_atoi(argv[3]);
	philos->time_sleep = ft_atoi(argv[4]);
	if (has_five_args)
		philos->nbr_times_must_eat = ft_atoi(argv[4]);
}

t_bool	ft_is_number(char *str)
{
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (FALSE);
		str++;
	}
	return (TRUE);
}

t_bool	ft_is_all_number(char *argv[])
{
	size_t	index;

	index = 1;
	while (argv[index])
	{
		if (!ft_is_number(argv[index]))
			return (FALSE);
		index++;
	}
	return (TRUE);
}

t_bool	ft_has_valid_args(int argc, char *argv[])
{
	if (argc < 5 || argc > 6)
	{
		printf("You can run only with 4 or 5 args!\n");
		return (FALSE);
	}
	if (!ft_is_all_number(argv))
	{
		printf("All args must be numeric!\n");
		return (FALSE);
	}
	return (TRUE);
}

int	main(int argc, char *argv[])
{
	t_philo	philos;
	if (!ft_has_valid_args(argc, argv))
		return (ERROR_CODE);
	ft_load_args(&philos, argv, argc == ARG_NUMBER_OF_TIMES_MUST_EAT);
	return (SUCCESS_CODE);
}