/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 21:40:31 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/03/21 19:10:36 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_bool	ft_is_number(char *str)
{
	int	nbr;

	nbr = ft_atoi(str);
	if (nbr == INT_MAX && ft_strncmp(str, INT_MAX_STR, ft_strlen(INT_MAX_STR)))
		return (FALSE);
	if (nbr == INT_MIN && ft_strncmp(str, INT_MIN_STR, ft_strlen(INT_MIN_STR)))
		return (FALSE);
	if (nbr <= 0)
		return (FALSE);
	if (!ft_is_number2(str))
		return (FALSE);
	return (TRUE);
}

t_bool	ft_is_all_number(char *argv[])
{
	size_t	index;

	index = 1;
	while (argv[index])
	{
		if (!ft_is_number(argv[index]))
		{
			printf("All arguments must be integers between 1 to %d!\n",
				INT_MAX);
			return (FALSE);
		}
		index++;
	}
	return (TRUE);
}

t_bool	ft_max_philo_nbr(char *nbr_philo_str)
{
	int	nbr_philo;

	nbr_philo = ft_atoi(nbr_philo_str);
	if (!(nbr_philo > 0 && nbr_philo <= MAX_PHILO_NBR))
	{
		printf("You can only run from 1 to %d philosophers\n", MAX_PHILO_NBR);
		return (FALSE);
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
	if (!ft_max_philo_nbr(argv[1]) || !ft_is_all_number(argv))
		return (FALSE);
	return (TRUE);
}
