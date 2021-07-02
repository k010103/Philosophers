/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phlio_forks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 17:16:12 by junmkang          #+#    #+#             */
/*   Updated: 2021/07/02 18:17:21 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int		philo_forks(t_philo *philo)
{
	if (philo->p_ptr % 2 == 0)
		vsleep(1);
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
