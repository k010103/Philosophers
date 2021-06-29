/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:37:20 by junmkang          #+#    #+#             */
/*   Updated: 2021/06/29 23:08:02 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"


// last-eat - 현재 시간.
// last_eat - time < info->eat : 죽지않음.
// 마지막 식사시간 - usleep 이후 현재시간. :
// {time_ms} {philo_ptr} is eating
int		philo_eat(t_pthread *pthread)
{
	struct timeval	present_time;
	struct timeval	last_time;
	int				philo_ptr;

	philo_ptr = pthread->p_num;
	last_time = pthread->last_eat_time;

	// if ()
	// pthread_mutex_lock(g_argv_info.fork[pthread->p_num]);
	// pthread_mutex_lock(pthread->p_num - 1);

	gettimeofday(&present_time, NULL);
	print_philo_msg(present_time.tv_usec - g_argv_info.start_time.tv_usec, pthread->p_num + 1, EatMsg);
	vsleep(g_argv_info.eat); // 200 while(0 -> 200) sleep(1);
	if (present_time.tv_usec - last_time.tv_usec < g_argv_info.die)
	{
		gettimeofday(&last_time, NULL);
		pthread->last_eat_time = last_time;
	}
	else
		return (_ERROR);

	// pthread_mutex_unlock(&fork[pthread->p_num]);
	// pthread_mutex_unlock((&fork[pthread->p_num - 1]);

	return (_OK);
}
