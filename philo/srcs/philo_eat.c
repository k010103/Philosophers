/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:37:20 by junmkang          #+#    #+#             */
/*   Updated: 2021/06/29 18:18:49 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"


// last-eat - 현재 시간.
// last_eat - time < info->eat : 죽지않음.
// 마지막 식사시간 - usleep 이후 현재시간. :
int		philo_eat(t_pthread *pthread)
{
	struct timeval	present_time;
	struct timeval	last_time;
	int				philo_ptr;

	philo_ptr = pthread->p_num;
	last_time = pthread->last_eat_time;
	// {time_ms} {philo_ptr} is eating
	// printf("time = %d\n", last_time.tv_usec);
	usleep(g_argv_info.eat * 100);
	gettimeofday(&present_time, NULL);
	printf("%d %d time = %d\n", last_time.tv_usec, present_time.tv_usec, last_time.tv_usec - present_time.tv_usec);
	// 살음.
	if (last_time.tv_usec - present_time.tv_usec < g_argv_info.die)
	{
		gettimeofday(&last_time, NULL);
		pthread->last_eat_time = last_time;
	}
	else
		return (_ERROR);

	return (_OK);
}

// int		test(void)
// {
	// struct timeval	start;
	// struct timeval	end;

	// gettimeofday(&start, NULL);
    // usleep(info->eat);
    // gettimeofday(&end, NULL);

    // int seconds  = end.tv_sec  - start.tv_sec;
    // int useconds = end.tv_usec - start.tv_usec;
	// printf("info->eat = %d\n", info->eat);
	// printf("seconds = %d\n", seconds);
	// printf("useconds = %d\n", useconds);

// 	return (_OK);
// }
