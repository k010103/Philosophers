/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 21:17:19 by junmkang          #+#    #+#             */
/*   Updated: 2021/06/30 21:51:34 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int		allocate_mutex_junmkang(void)
{
	int		count;
	int		x;

	count = 0;
	while (count < g_argv_info.philo_num)
	{
		if ((x = pthread_mutex_init(&(loop_info.fork[count]), NULL)))
			return (_ERROR);
		count++;
	}
	if((pthread_mutex_init(&loop_info.mutex_text, NULL)))
		return (_ERROR);
	return (_OK);
}

int		philo_setup(t_philo *philos)
{
	philos->pthread = ft_malloc(sizeof(philos->pthread) * g_argv_info.philo_num);
	loop_info.fork = ft_malloc(sizeof(pthread_mutex_t) * g_argv_info.philo_num);
	if ((allocate_mutex_junmkang()))
		return (_ERROR);
	loop_info.start_time = now_time();
	philo_loop(philos);
	philo_join(philos);
	fork_destroy();
	// int_test(test, &info);
	// printf("philo_num = %d\n", philo->g_argv_info.philo_num);

	return (_OK);
}
