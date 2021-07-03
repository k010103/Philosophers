/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:36:49 by junmkang          #+#    #+#             */
/*   Updated: 2021/07/03 18:03:07 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

// {time_ms} {philo_ptr} is sleeping
int			philo_sleep(t_philo *philo)
{
	if (philo->info->die_or_life || philo->info->it_one)
		return (_ERROR);
	philo_unforks(philo);
	print_philo_msg(philo, SleepMsg);
	vsleep((unsigned int)philo->info->sleep);
	return (_OK);
}
