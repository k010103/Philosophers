/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 23:56:34 by junmkang          #+#    #+#             */
/*   Updated: 2021/07/05 13:44:13 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "philo.h"

int	print_error_msg(char *str)
{
	write(1, str, ft_strlen(str));
	return (_ERROR);
}

int	print_philo_msg(t_philo *philo, char *msg)
{
	long long		time;

	pthread_mutex_lock(&philo->info->mutex_text);
	if (philo->info->die_or_life)
	{
		pthread_mutex_unlock(&philo->info->mutex_text);
		return (_ERROR);
	}
	time = now_time() - philo->info->start_time;
	printf("%lld\t%d\t%s\n", time, philo->p_ptr + 1, msg);
	pthread_mutex_unlock(&philo->info->mutex_text);
	return (_OK);
}
