/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 21:35:15 by junmkang          #+#    #+#             */
/*   Updated: 2021/07/02 18:22:46 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int			philo_join(t_info *info)
{
	int		count;

	count = 0;
	while (count < info->philo_num)
	{
		pthread_join(info->philos[count].thread, NULL);
		count++;
	}
	return (_OK);
}

int			fork_destroy(t_info *info)
{
	int		count;

	count = 0;
	while (count < info->philo_num)
	{
		pthread_mutex_destroy(&info->forks[count]);
		count++;
	}
	return (_OK);
}
