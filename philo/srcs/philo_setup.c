/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 21:17:19 by junmkang          #+#    #+#             */
/*   Updated: 2021/06/29 22:43:27 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int		allocate_mutex_junmkang(void)
{
	int		count;

	count = 0;
	while (count < g_argv_info.philo_num)
	{
		if ((pthread_mutex_init(&(g_argv_info.fork[count]), NULL)))
			return (_ERROR);
		count++;
	}
	if((pthread_mutex_init(&g_argv_info.mutex_text, NULL)))
		return (_ERROR);
	return (_OK);
}

int		philo_setup(t_philo *philos)
{
	philos->pthread = ft_malloc(sizeof(philos->pthread) * g_argv_info.philo_num);
	g_argv_info.fork = ft_malloc(sizeof(g_argv_info.fork) * g_argv_info.philo_num);
	if ((allocate_mutex_junmkang()))
		return (_ERROR);
	philo_loop(philos);
	philo_join(philos);
	// int_test(test, &info);
	// printf("philo_num = %d\n", philo->g_argv_info.philo_num);

	return (_OK);
}
