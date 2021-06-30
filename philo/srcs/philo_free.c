/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 21:35:15 by junmkang          #+#    #+#             */
/*   Updated: 2021/06/30 21:43:17 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int			philo_join(t_philo *philos)
{
	int		count;

	count = 0;

	while (count < g_argv_info.philo_num)
	{
		pthread_join(philos->pthread[count].philo, NULL);
		count++;
	}
	return (_OK);
}

int			fork_destroy(void)
{
	int		count;

	count = 0;
	while (count < g_argv_info.philo_num)
	{
		pthread_mutex_destroy(&loop_info.fork[count]);
		count++;
	}
	return (_OK);
}
