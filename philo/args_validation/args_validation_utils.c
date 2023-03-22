/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validation_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 21:40:31 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/03/21 19:10:22 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_bool	ft_advance_plus_sign(char **str)
{
	if (**str == '+')
		(*str)++;
	if (!**str)
		return (FALSE);
	return (TRUE);
}

t_bool	ft_is_number2(char *str)
{
	if (!ft_advance_plus_sign(&str))
		return (FALSE);
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (FALSE);
		str++;
	}
	return (TRUE);
}
