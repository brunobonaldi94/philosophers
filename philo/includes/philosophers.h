/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:26:03 by harndt            #+#    #+#             */
/*   Updated: 2023/03/11 15:41:22 by bbonaldi         ###   ########.fr       */
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
int			ft_atoi(const char *nptr);
char		*ft_strdup(const char *s);
// =============================================================================
// ARGS VALIDATION
// =============================================================================
t_bool		ft_has_valid_args(int argc, char *argv[]);

// =============================================================================
// THREADS
// =============================================================================
void		ft_create_philosophers(t_philo *philo, size_t nbr_philos);

// =============================================================================
// PHILO ROUTINE
// =============================================================================
void		ft_eat_routine(t_philo *philo, int philo_id);
void		ft_sleep_routine(t_philo *philo, int philo_id);
void		ft_think_routine(t_philo *philo, int philo_id);
void		ft_assign_forks(int nbr_philos, int philo_id, int forks[2]);
// =============================================================================
// PHILO LOGGERS
// =============================================================================
void		ft_log_philo(t_philo *philo, int philo_id,
				t_philo_status cur_status);
void		ft_print_args(t_philo *philo);
// =============================================================================
// TIME
// =============================================================================
t_time_ms	ft_get_time_ms(void);
t_time_ms	ft_get_elapsed_time(t_time_ms start_time);
void		ft_usleep(t_time_ms end_time);
// =============================================================================
// FREE PROGRAM
// =============================================================================
void		ft_free_philosophers(t_philo *philo);
// =============================================================================
// PHILO MUTEX
// =============================================================================
void		ft_init_mutex(t_philo *philo);
void		ft_destroy_mutex(t_philo *philo);
t_bool		ft_should_stop_dinner(t_philo *philo);
void		ft_stop_dinner(t_philo *philo, t_bool should_stop_dinner);
t_bool		ft_should_die(t_philo *philo, int philo_id);
// =============================================================================
// PHILO MUTEX
// =============================================================================
t_bool		ft_init_watcher(t_philo *philo);
#endif
