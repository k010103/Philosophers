/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 21:17:19 by junmkang          #+#    #+#             */
/*   Updated: 2021/06/29 21:19:41 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int		allocate_fork_junmkang(t_philo *philo)
{
	int		count;

	count = 0;
	while (count < g_argv_info.philo_num)
	{
		if ((pthread_mutex_init(&(philo->pthread[count].fork), NULL)))
			return (_ERROR);
		count++;
	}
	return (_OK);
}

int		philo_setup(t_philo *philos)
{
	philos->pthread = ft_malloc(sizeof(philos->pthread) * g_argv_info.philo_num);

	if ((allocate_fork_junmkang(philos)))
		return (_ERROR);
	philo_loop(philos);
	philo_free_join(philos);
	// int_test(test, &info);
	// printf("philo_num = %d\n", philo->g_argv_info.philo_num);

	return (_OK);
}
