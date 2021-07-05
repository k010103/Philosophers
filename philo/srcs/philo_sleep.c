/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:36:49 by junmkang          #+#    #+#             */
/*   Updated: 2021/07/05 15:03:07 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "philo.h"

int	philo_sleep(t_philo *philo)
{
	if (philo->info->die_or_life || philo->info->it_one)
		return (_ERROR);
	philo->last_eat_time = now_time() - philo->info->eat;
	print_philo_msg(philo, SLEEP_MSG);
	vsleep((unsigned int)philo->info->sleep);
	return (_OK);
}
