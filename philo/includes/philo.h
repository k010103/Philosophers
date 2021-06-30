/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 21:21:29 by junmkang          #+#    #+#             */
/*   Updated: 2021/06/30 22:17:13 by junmkang         ###   ########.fr       */
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

/*
** global variables =======================================
*/

t_info		g_argv_info;
t_p_info	loop_info;

/*
**	ft_utils ==============================================
*/

void		*ft_malloc(size_t size);
size_t		ft_strlen(const char *str);
int			ft_atoi(const char *str);

/*
** philo_utils ============================================
*/

void		vsleep(unsigned int time);
long long	now_time(void);

/*
** print_msg ==============================================
*/

int			print_philo_msg(long long time, int philo_ptr, t_msg msg);
int			print_error_msg(char *str);

/*
** philo_free =============================================
*/

int			philo_join(t_philo *philos);
int			fork_destroy(void);

/*
** philo_setup ============================================
*/

int			allocate_mutex_junmkang(void);
int			philo_setup(t_philo *philos);

/*
** philo_loop =============================================
*/

int			philo_loop(t_philo *philos);

/*
** philo_eat ==============================================
*/

int			philo_eat(t_pthread *pthread);

/*
** philo_sleep ============================================
*/

int			philo_sleep(t_pthread *pthread);

/*
** philo_think ============================================
*/

int			philo_think(t_pthread *pthread);

/*
** philo_die ==============================================
*/
int			philo_die(t_pthread *pthread);

#	endif
