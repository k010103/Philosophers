/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 23:56:34 by junmkang          #+#    #+#             */
/*   Updated: 2021/06/29 22:43:54 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int		print_error_msg(char *str)
{
	write(1, str, ft_strlen(str));
	return (_ERROR);
}

// 출력 도중에 문자가 짤리면 안되므로 mutex로 묶어서 출력을 해줘야함
int		print_philo_msg(int time, int philo_ptr, t_msg msg)
{
	pthread_mutex_lock(&g_argv_info.mutex_text);
	if (msg == ForkMsg)
		printf("%d %d %s\n", time, philo_ptr, "has taken a fork");
	else if (msg == EatMsg)
		printf("%d %d %s\n", time, philo_ptr, "is eating");
	else if (msg == SleepMsg)
		printf("%d %d %s\n", time, philo_ptr, "is sleeping");
	else if (msg == ThinkMsg)
		printf("%d %d %s\n", time, philo_ptr, "is thinking");
	else if (msg == DiedMsg)
		printf("%d %d %s\n", time, philo_ptr, "died");
	else
		return (_ERROR);
	pthread_mutex_unlock(&g_argv_info.mutex_text);
	return (_OK);
}
