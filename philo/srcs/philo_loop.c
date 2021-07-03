/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:19:18 by junmkang          #+#    #+#             */
/*   Updated: 2021/07/03 22:27:17 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void		*philo_action(void *v_pthread)
{
	t_philo		*philo;

	philo = (t_philo *)v_pthread;
	if (philo->p_ptr % 2 == 0)
		vsleep(3);
	philo->last_eat_time = now_time();
	while (!philo->info->die_or_life)
	{
		philo_forks(philo);
		philo_eat(philo);
		philo_unforks(philo);
		philo_sleep(philo);//100 ms
		philo_think(philo);// x + 100 + 2 ms
		//revision_time = current - 100;// x+2
	}
	return (NULL);
}

int			create_philos(t_info *info)
{
	int			count;
	pthread_t	monitor;

	count = 0;
	while(count < info->philo_num)
	{
		if ((pthread_create(&info->philos[count].thread, \
						NULL, philo_action, (void *)&info->philos[count])))
						return (_ERROR);
		count++;
	}
	if ((pthread_create(&monitor, NULL, philo_monitor, (void *)info)))
					return (_ERROR);
	pthread_detach(monitor);
	return (_OK);
}

int				philo_loop(t_info *info)
{
	if ((create_philos(info)))
		return (print_error_msg("create_philos : error\n"));
	return (_OK);
}

