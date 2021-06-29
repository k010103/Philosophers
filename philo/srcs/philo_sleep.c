/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:36:49 by junmkang          #+#    #+#             */
/*   Updated: 2021/06/29 23:08:10 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

// {time_ms} {philo_ptr} is sleeping
int			philo_sleep(t_pthread *pthread)
{
	struct timeval	present_time;

	gettimeofday(&present_time, NULL);
	print_philo_msg(present_time.tv_usec - g_argv_info.start_time.tv_usec, pthread->p_num + 1, SleepMsg);
	vsleep(g_argv_info.sleep);
	return (_OK);
}
