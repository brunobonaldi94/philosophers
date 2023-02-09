/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 21:40:31 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/02/08 21:50:17 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
		printf("All arguments must be numeric!\n");
		return (FALSE);
	}
	return (TRUE);
}
