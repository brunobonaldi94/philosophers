/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 21:27:40 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/02/01 22:17:59 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		if (c == ' ' || c == '\f' || c == '\n'
			|| c == '\r' || c == '\t' || c == '\v')
			return (2);
		return (1);
	}
	return (0);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	const char	*nptr_ptr;
	int			sign_result;
	int			result;

	nptr_ptr = nptr;
	result = 0;
	sign_result = 1;
	while (ft_isascii(*nptr_ptr) == 2)
		nptr_ptr++;
	if (*nptr_ptr == '+' || *nptr_ptr == '-')
	{
		if (*nptr_ptr == '-')
			sign_result *= -1;
		nptr_ptr++;
	}
	while (ft_isdigit(*nptr_ptr))
	{
		result = (result * 10) + (*nptr_ptr - '0');
		nptr_ptr++;
	}
	return (result * sign_result);
}
