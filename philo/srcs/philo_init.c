/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 21:17:19 by junmkang          #+#    #+#             */
/*   Updated: 2021/07/05 15:11:45 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "philo.h"

int	init_philo_junmkang(t_info *info)
{
	int	count;

	count = 0;
	info->start_time = now_time();
	while (count < info->philo_num)
	{
		info->philos[count].p_ptr = count;
		if ((pthread_mutex_init(&(info->forks[count]), NULL)))
			return (_ERROR);
		info->philos[count].r_fork = &info->forks[count];
		if (count == 0)
			info->philos[count].l_fork = &info->forks[info->philo_num - 1];
		else
			info->philos[count].l_fork = &info->forks[count - 1];
		info->philos[count].info = info;
		count++;
	}
	return (_OK);
}

int	init_malloc_junmkang(t_info *info)
{
	info->philos = ft_malloc(sizeof(t_philo) * (info->philo_num));
	info->forks = ft_malloc(sizeof(pthread_mutex_t) * (info->philo_num));
	if (!(info->philos) || !(info->forks))
		return (print_error_msg("malloc : error\n"));
	if (info->philo_num == 1)
		info->it_one = 1;
	pthread_mutex_init(&(info->mutex_text), NULL);
	pthread_mutex_init(&(info->died_mutex), NULL);
	return (_OK);
}

int	philo_setup(t_info *info)
{
	if ((init_malloc_junmkang(info)))
		return (print_error_msg("init_malloc : error\n"));
	if ((init_philo_junmkang(info)))
		return (print_error_msg("init_philo : error\n"));
	return (_OK);
}
