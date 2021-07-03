/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 20:38:35 by junmkang          #+#    #+#             */
/*   Updated: 2021/07/03 22:26:05 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int			philo_think(t_philo *philo)
{
	if (philo->info->die_or_life || philo->info->it_one)
		return (_ERROR);
	// revision_time
	// philo->revision_time = ms_now_time(philo) - (long long)(philo->info->sleep);

	print_philo_msg(philo, THINK_MSG);
	return (_OK);
}
