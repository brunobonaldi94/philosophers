/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:26:03 by harndt            #+#    #+#             */
/*   Updated: 2023/02/01 22:18:54 by bbonaldi         ###   ########.fr       */
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

#endif