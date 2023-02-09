/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:26:03 by harndt            #+#    #+#             */
/*   Updated: 2023/02/08 22:40:02 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

// =============================================================================
// LOCAL LIBRARIES
// =============================================================================

# include "defines.h"
// =============================================================================
// EXTERNAL LIBRARIES
// =============================================================================

# include <unistd.h>			/* write usleep */
# include <stdio.h>				/* printf */
# include <stdlib.h>			/* malloc free*/
# include <string.h>			/* memset */
# include <sys/time.h>			/* gettimeofday */
# include <pthread.h>			
								/* pthread_create, pthread_detach, \ 
								   pthread_join, pthread_mutex_init, \
								   pthread_mutex_destroy, pthread_mutex_lock, \
								   pthread_mutex_unlock
								*/
# include "structs.h"
// =============================================================================
// FUNCTIONS
// =============================================================================
// =============================================================================
// UTILS
// =============================================================================
int	ft_atoi(const char *nptr);

// =============================================================================
// ARGS VALIDATION
// =============================================================================
t_bool	ft_has_valid_args(int argc, char *argv[]);

// =============================================================================
// THREADS
// =============================================================================
void	ft_create_philosophers(t_philo *philo, size_t nbr_philos);

// =============================================================================
// FREE PROGRAM
// =============================================================================
void	ft_free_philosophers(t_philo *philo);

#endif