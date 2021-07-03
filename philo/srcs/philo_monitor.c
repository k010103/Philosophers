/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 12:34:17 by junmkang          #+#    #+#             */
/*   Updated: 2021/07/03 22:41:52 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int		must_eat_chk(t_info *info)
{
	int		count;

	count = 0;
	while (count < info->philo_num)
	{
		if (info->philos[count].eaten_num < info->must_eat)
			return (_ERROR);
		count++;
	}
	return (_OK);
}

void			*philo_monitor(void *pthread)
{
	t_info		*info;
	t_philo		*philo;
	long long	time;
	int			count;

	info = (t_info *)pthread;
	vsleep(info->die);
	while (!info->monitor_life)
	{
		count = -1;
		while (count++ < info->philo_num)
		{
			philo = &info->philos[count];
			time = now_time();
			if (time - philo->last_eat_time > (long long)(info->die))
			{
				print_philo_msg(philo, DIED_MSG);
				info->die_or_life = 1;
				info->monitor_life = 1;
			}
			else if (info->must_eat)
				if (!(must_eat_chk(info)))
				{
					info->monitor_life = 1;
					info->die_or_life = 1;
				}
		}
	}
	return (NULL);
}
