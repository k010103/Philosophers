/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 12:34:17 by junmkang          #+#    #+#             */
/*   Updated: 2021/07/08 21:29:29 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "philo.h"

static int	must_eat_chk(t_info *info)
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

void	*philo_must_eat(void *pthread)
{
	t_info	*info;

	info = (t_info *)pthread;
	while (!info->monitor_life && !info->die_or_life)
	{
		if (!must_eat_chk(info))
		{
			info->monitor_life = 1;
			info->die_or_life = 1;
		}
	}
	return (NULL);
}


void	*philo_monitor(void *pthread)
{
	t_philo		*philo;
	long long	time;

	philo = (t_philo *)pthread;
	vsleep(philo->info->die);
	while (!philo->info->die_or_life)
	{
		time = now_time();
		if (time - philo->last_eat_time > (long long)(philo->info->die))
		{
			pthread_mutex_lock(&philo->info->died_mutex);
			philo->info->die_or_life = 1;
			time -= philo->info->start_time;
			printf("%lld\t%d\t%s\n", time, philo->p_ptr + 1, DIED_MSG);
		}
	}
	return (NULL);
}
