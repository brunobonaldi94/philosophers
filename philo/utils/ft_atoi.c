/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 21:27:40 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/03/21 19:09:13 by bbonaldi         ###   ########.fr       */
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

static long long	check_over_under_flow(int sign_result, long long result)
{
	if (sign_result > 0 && result >= (long long)INT_MAX)
		return ((long long)(INT_MAX));
	if (sign_result < 0 && (-1 * result) <= (long long)INT_MIN)
		return ((long long)(INT_MIN));
	return (result);
}

int	ft_atoi(const char *nptr)
{
	const char		*nptr_ptr;
	int				sign_result;
	long long		result;

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
	result = check_over_under_flow(sign_result, result);
	return (result * sign_result);
}
