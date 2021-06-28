/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:37:20 by junmkang          #+#    #+#             */
/*   Updated: 2021/06/28 20:50:13 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"


// last-eat - 현재 시간.
// last_eat - time < info->eat : 죽지않음.
int		philo_eat(t_info *info, t_philo *philo, int philo_ptr)
{
	struct timeval	time;
	struct timeval	last_time;

	last_time = philo[philo_ptr].cp_info.last_eat_time;
	usleep(info->eat);
	gettimeofday(&time, NULL);
	// 살음.
	if (last_time.tv_usec - time.tv_usec < info->die)
	{
		gettimeofday(&last_time, NULL);
		philo[philo_ptr].cp_info.last_eat_time = last_time;
	}
	else
		return (_ERROR);

	return (_OK);
}

int		test(void)
{
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

	return (_OK);
}
