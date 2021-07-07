/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:19:18 by junmkang          #+#    #+#             */
/*   Updated: 2021/07/07 10:09:27 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "philo.h"

void	*philo_action(void *v_pthread)
{
	t_philo		*philo;

	philo = (t_philo *)v_pthread;
	if (philo->p_ptr % 2 == 0 && philo->info->philo_num > 1)
		vsleep(philo->info->eat);
	philo->last_eat_time = now_time();
	while (!philo->info->die_or_life)
	{
		philo_forks(philo);
		philo_eat(philo);
		philo_unforks(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

// pthread_create 함수가 실패하였을경우 에러처리를 꼭 해줘야할까..?

static int	create_philos_must_eat(t_info *info)
{
	int			error;
	pthread_t	monitor;

	error = pthread_create(&monitor, NULL, philo_must_eat, (void *)info);
	if (error)
		return (_ERROR);
	pthread_detach(monitor);
	return (_OK);
}

int	create_philos(t_info *info)
{
	int			count;
	int			error;
	pthread_t	monitor;

	count = 0;
	while (count < info->philo_num)
	{
		error = pthread_create(&info->philos[count].thread, \
						NULL, philo_action, (void *)&info->philos[count]);
		if (error)
			return (_ERROR);
		error = pthread_create(&monitor, NULL, \
								philo_monitor, (void *)&info->philos[count]);
		if (error)
			return (_ERROR);
		pthread_detach(monitor);
		count++;
	}
	if (info->must_eat != 0 && info->philo_num > 1)
		create_philos_must_eat(info);
	return (_OK);
}

int	philo_loop(t_info *info)
{
	if ((create_philos(info)))
		return (print_error_msg("create_philos : error\n"));
	return (_OK);
}
