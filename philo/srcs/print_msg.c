/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 23:56:34 by junmkang          #+#    #+#             */
/*   Updated: 2021/07/03 22:15:00 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int		print_error_msg(char *str)
{
	write(1, str, ft_strlen(str));
	return (_ERROR);
}

int		print_philo_msg(t_philo *philo, char *msg)
{
	long long		time;

	time = now_time() - philo->info->start_time;
	pthread_mutex_lock(&(philo->info->mutex_text));
	printf("%lld\t%d\t%s\n", time, philo->p_ptr + 1, msg);
	pthread_mutex_unlock(&(philo->info->mutex_text));
	return (_OK);
}
