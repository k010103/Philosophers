/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 20:38:35 by junmkang          #+#    #+#             */
/*   Updated: 2021/07/04 22:50:28 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "philo.h"

int	philo_think(t_philo *philo)
{
	if (philo->info->die_or_life || philo->info->it_one)
		return (_ERROR);
	philo->last_eat_time = now_time() - philo->info->sleep;
	print_philo_msg(philo, THINK_MSG);
	return (_OK);
}
