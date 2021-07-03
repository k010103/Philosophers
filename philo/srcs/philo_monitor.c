/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 12:34:17 by junmkang          #+#    #+#             */
/*   Updated: 2021/07/03 15:53:00 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		*philo_monitor(void *pthread)
{
	t_philo		*monitor;
	long long	time;

	monitor = (t_philo *)pthread;
	vsleep(monitor->info->die);
	while (1)
	{
		time = now_time();
		if (time - monitor->last_eat_time > (long long)(monitor->info->die))
		{
			print_philo_msg(monitor, DiedMsg);
			exit (0);
		}
	}
	return (NULL);
}
