/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:37:20 by junmkang          #+#    #+#             */
/*   Updated: 2021/07/03 22:28:50 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int		philo_eat(t_philo *philo)
{
	long long		present_time;
	long long		last_time;

	if (philo->info->die_or_life || philo->info->it_one)
		return (_ERROR);
	print_philo_msg(philo, EAT_MSG);
	vsleep((unsigned int)philo->info->eat);
	present_time = now_time();
	if (present_time - philo->last_eat_time <= (long long)(philo->info->die))
	{
		philo->eaten_num += 1;
		last_time = now_time();
		philo->last_eat_time = last_time;
	}
	else
	{
		philo->info->die_or_life = 1;
		return (_ERROR);
	}
	return (_OK);
}
