/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 21:21:29 by junmkang          #+#    #+#             */
/*   Updated: 2021/06/22 02:33:50 by junmkang         ###   ########.fr       */
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
** ft_utils ===============================================
*/

size_t		ft_strlen(const char *str);
int			ft_atoi(const char *str);

/*
** print_error_msg ========================================
*/

int			print_error_msg(char *str);

#	endif
