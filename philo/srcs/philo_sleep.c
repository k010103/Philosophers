/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:36:49 by junmkang          #+#    #+#             */
/*   Updated: 2021/06/30 22:22:46 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

// {time_ms} {philo_ptr} is sleeping
int			philo_sleep(t_pthread *pthread)
{
	long long	present_time;

	present_time = now_time();
	print_philo_msg(present_time - loop_info.start_time, pthread->p_num + 1, SleepMsg);
	vsleep(g_argv_info.sleep);
	return (_OK);
}
