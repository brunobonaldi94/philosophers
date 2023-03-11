/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 22:21:52 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/03/11 15:37:52 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
