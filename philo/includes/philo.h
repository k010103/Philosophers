/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 21:21:29 by junmkang          #+#    #+#             */
/*   Updated: 2021/06/29 18:01:57 by junmkang         ###   ########.fr       */
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

/*
**	ft_utils ===============================================
*/

void		*ft_malloc(size_t size);
size_t		ft_strlen(const char *str);
int			ft_atoi(const char *str);

/*
** philo_utils ============================================
*/

int		get_current_time(int elapse);

/*
** print_error_msg ========================================
*/

int			print_error_msg(char *str);

/*
** philo_loop =============================================
*/

int		philo_setup(t_philo *philos);
// int			philo_loop(t_info info);

/*
** philo_eat ==============================================
*/
int		philo_eat(t_pthread *pthread);


#	endif
