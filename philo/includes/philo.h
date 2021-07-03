/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 21:21:29 by junmkang          #+#    #+#             */
/*   Updated: 2021/07/03 22:24:25 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef PHILO_H
#	define PHILO_H

/*
** header =================================================
*/

#	include <stdio.h>
#	include <pthread.h>
#	include <string.h>
#	include <stdlib.h>
#	include <unistd.h>
#	include <sys/time.h>

/*
** include ================================================
*/

#	include "philo_struct.h"

/*
** define =================================================
*/

#	define _ERROR	1
#	define _OK		0

#	define FORK_MSG		"has taken a fork"
#	define EAT_MSG		"is eating"
#	define SLEEP_MSG	"is sleeping"
#	define THINK_MSG	"is thinking"
#	define DIED_MSG		"died"

/*
**	ft_utils ==============================================
*/

void		*ft_malloc(size_t size);
size_t		ft_strlen(const char *str);
int			ft_atoi(const char *str);

/*
**	info_init =============================================
*/

int			info_init(t_info *info, int argc, char **argv);

/*
** philo_utils ============================================
*/

void		vsleep(unsigned int time);
long long	now_time(void);
long long	ms_now_time(t_philo *philo);

/*
** print_msg ==============================================
*/

int			print_philo_msg(t_philo *philo, char *msg);
int			print_error_msg(char *str);

/*
** philo_free =============================================
*/

int			philo_join(t_info *info);
int			fork_destroy(t_info *info);
int			philo_free(t_info *info);

/*
** philo_init =============================================
*/

int			init_philo_junmkang(t_info *info);
int			philo_setup(t_info *info);

/*
** philo_loop =============================================
*/

void		*philo_action(void *v_pthread);
int			create_philos(t_info *info);
int			philo_loop(t_info *info);

/*
** philo_forks ============================================
*/

int			philo_forks(t_philo *philo);
int			philo_unforks(t_philo *philo);

/*
** philo_eat ==============================================
*/

int			philo_eat(t_philo *philo);

/*
** philo_sleep ============================================
*/

int			philo_sleep(t_philo *philo);

/*
** philo_think ============================================
*/

int			philo_think(t_philo *philo);

/*
** philo_die ==============================================
*/

void		*philo_monitor(void *pthread);

#	endif
