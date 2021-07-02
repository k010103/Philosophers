/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:36:49 by junmkang          #+#    #+#             */
/*   Updated: 2021/07/02 17:47:45 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

// {time_ms} {philo_ptr} is sleeping
int			philo_sleep(t_philo *philo)
{
	philo_unforks(philo);
	print_philo_msg(philo, SleepMsg);
	vsleep((unsigned int)philo->info->sleep);
	return (_OK);
}
