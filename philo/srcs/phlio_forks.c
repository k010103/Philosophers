/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phlio_forks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 17:16:12 by junmkang          #+#    #+#             */
/*   Updated: 2021/07/03 18:03:16 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

// 1명인 경우 생존시간 이후에 죽었다고 표시가 되어야하므로 bool 형을 1개 더 만들어줘야함.

int		philo_forks(t_philo *philo)
{
	if (philo->info->philo_num <= 1)
	{
		philo->info->it_one = 1;
		return (_ERROR);
	}
	pthread_mutex_lock(philo->r_fork);
	print_philo_msg(philo, ForkMsg);
	pthread_mutex_lock(philo->l_fork);
	print_philo_msg(philo, ForkMsg);
	return (_OK);
}

int		philo_unforks(t_philo *philo)
{
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	return (_OK);
}
