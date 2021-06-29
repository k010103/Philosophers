/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:37:20 by junmkang          #+#    #+#             */
/*   Updated: 2021/06/29 18:40:08 by junmkang         ###   ########.fr       */
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
	usleep(g_argv_info.eat);
	gettimeofday(&present_time, NULL);

	printf("number = %d %d\n", pthread->p_num, present_time.tv_usec - last_time.tv_usec);
	// if (present_time.tv_usec - last_time.tv_usec < g_argv_info.die)
	// {
		gettimeofday(&last_time, NULL);
		pthread->last_eat_time = last_time;
		// printf("%d\n", last_time.tv_usec);
	// }
	// else
	// {
	// 	// printf("else return\n");
	// 	return (_ERROR);
	// }

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
