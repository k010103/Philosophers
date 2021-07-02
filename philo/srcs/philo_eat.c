/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:37:20 by junmkang          #+#    #+#             */
/*   Updated: 2021/07/02 18:09:13 by junmkang         ###   ########.fr       */
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

	present_time = now_time();
	vsleep((unsigned int)philo->info->eat);
	if (present_time - philo->last_eat_time < philo->info->die)
	{
		print_philo_msg(philo, EatMsg);
		last_time = now_time();
		philo->last_eat_time = last_time;
	}
	else
		return (_ERROR);
	return (_OK);
}
