/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_die.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:37:23 by junmkang          #+#    #+#             */
/*   Updated: 2021/06/29 22:32:39 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int			philo_die(t_pthread *pthread)
{
	struct timeval	present_time;

	gettimeofday(&present_time, NULL);
	print_philo_msg(present_time.tv_usec - g_argv_info.start_time.tv_usec, pthread->p_num + 1, DiedMsg);
	exit(0);
	return (_OK);
}
