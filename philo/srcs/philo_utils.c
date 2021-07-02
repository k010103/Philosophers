/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:29:33 by junmkang          #+#    #+#             */
/*   Updated: 2021/07/02 15:12:28 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

long long		now_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	// 이 공식이 왜 나온거야..?
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

void	vsleep(unsigned int time)
{
	unsigned int	finish_time;

	finish_time = time + now_time();
	while(finish_time > (unsigned int)now_time())
	{usleep(50);}
}
