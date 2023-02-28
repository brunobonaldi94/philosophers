/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:03:13 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/02/27 23:07:00 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_time_ms	ft_get_time_ms(void)
{
	t_timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((((long long)current_time.tv_sec) * 1000)
		+ (current_time.tv_usec / 1000));
}

t_time_ms	ft_get_elapsed_time(t_time_ms start_time)
{
	return (ft_get_time_ms() - start_time);
}
