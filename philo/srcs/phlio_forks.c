/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phlio_forks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 17:16:12 by junmkang          #+#    #+#             */
/*   Updated: 2021/07/03 22:26:14 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int		philo_forks(t_philo *philo)
{
	if (philo->info->philo_num <= 1)
	{
		philo->info->it_one = 1;
		return (_ERROR);
	}
	if (philo->info->die_or_life)
		return (_ERROR);
	pthread_mutex_lock(philo->r_fork);
	print_philo_msg(philo, FORK_MSG);
	pthread_mutex_lock(philo->l_fork);
	print_philo_msg(philo, FORK_MSG);
	return (_OK);
}

int		philo_unforks(t_philo *philo)
{
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	return (_OK);
}
