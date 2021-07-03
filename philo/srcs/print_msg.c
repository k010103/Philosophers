/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 23:56:34 by junmkang          #+#    #+#             */
/*   Updated: 2021/07/02 21:19:04 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int		print_error_msg(char *str)
{
	write(1, str, ft_strlen(str));
	return (_ERROR);
}

// 출력 도중에 문자가 짤리면 안되므로 mutex로 묶어서 출력을 해줘야함
int		print_philo_msg(t_philo *philo, char *msg)
{
	long long		time;

	time = now_time() - philo->info->start_time;
	pthread_mutex_lock(&(philo->info->mutex_text));
	printf("%lld\t%d\t%s\n", time, philo->p_ptr + 1, msg);
	pthread_mutex_unlock(&(philo->info->mutex_text));
	return (_OK);
}
