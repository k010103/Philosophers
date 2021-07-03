/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:19:18 by junmkang          #+#    #+#             */
/*   Updated: 2021/07/03 15:52:53 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void		*philo_action(void *v_pthread)
{
	t_philo		*philo;
	int			x;

	philo = (t_philo *)v_pthread;
	if (philo->p_ptr % 2 == 0)
		vsleep(1);
	philo->last_eat_time = now_time();
	while (1)
	{
		philo_forks(philo);
		if ((x = philo_eat(philo)))
			philo_die(philo);// x ms
		philo_sleep(philo);//100 ms
		philo_think(philo);// x + 100 + 2 ms
		//revision_time = current - 100;// x+2
	}
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
		if ((pthread_create(&monitor, \
						NULL, philo_monitor, (void *)&info->philos[count])))
						return (_ERROR);
		pthread_detach(monitor);
		count++;
	}
	return (_OK);
}

int				philo_loop(t_info *info)
{
	if ((create_philos(info)))
		return (print_error_msg("create_philos : error\n"));
	return (_OK);
}

