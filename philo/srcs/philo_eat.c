/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:37:20 by junmkang          #+#    #+#             */
/*   Updated: 2021/07/03 12:28:25 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"


// last-eat - 현재 시간.
// last_eat - time < info->eat : 죽지않음.
// 마지막 식사시간 - usleep 이후 현재시간. :
// {time_ms} {philo_ptr} is eating

int		philo_eat(t_philo *philo)
{
	long long		present_time;
	long long		last_time;

	vsleep((unsigned int)philo->info->eat);
	present_time = now_time();
	if (present_time - philo->last_eat_time < (long long)(philo->info->die))
	{
		print_philo_msg(philo, EatMsg);
		last_time = now_time();
		philo->last_eat_time = last_time;
	}
	else
		return (_ERROR);
	return (_OK);
}
