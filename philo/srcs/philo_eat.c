/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:37:20 by junmkang          #+#    #+#             */
/*   Updated: 2021/06/30 22:23:01 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"


// last-eat - 현재 시간.
// last_eat - time < info->eat : 죽지않음.
// 마지막 식사시간 - usleep 이후 현재시간. :
// {time_ms} {philo_ptr} is eating

int		philo_has_fork(t_pthread *pthread)
{
	long long		time;
	int				one_fork;
	int				two_fork;
	int				a;
	int				b;

	one_fork = pthread->p_num;
	if (pthread->p_num - 1 < 0)
		two_fork = 0;
	else
		two_fork = pthread->p_num - 1;
	a = pthread_mutex_lock(&(loop_info.fork[one_fork]));
	time = now_time();
	print_philo_msg(time - loop_info.start_time, \
					pthread->p_num + 1, ForkMsg);
	printf("lock_a = %d\n", a);
	printf("one_fork = %d\n", one_fork);
	b = pthread_mutex_lock(&(loop_info.fork[two_fork]));
	time = now_time();
	print_philo_msg(time - loop_info.start_time, \
					pthread->p_num + 1, ForkMsg);
	printf("lock_b = %d\n", b);
	printf("two_fork = %d\n", two_fork);
	return (_OK);
}

int		philo_has_unfork(t_pthread *pthread)
{
	int				one_fork;
	int				two_fork;
	int				a;
	int				b;

	one_fork = pthread->p_num;
	if (pthread->p_num - 1 < 0)
		two_fork = 0;
	else
		two_fork = pthread->p_num - 1;
	a = pthread_mutex_unlock(&(loop_info.fork[one_fork]));
	b = pthread_mutex_unlock(&(loop_info.fork[two_fork]));
	return (_OK);
}

int		philo_eat(t_pthread *pthread)
{
	long long		present_time;
	long long		last_time;
	int				philo_ptr;

	philo_ptr = pthread->p_num;
	last_time = pthread->last_eat_time;

	if (philo_ptr % 2 == 0)
		vsleep(1);
	philo_has_fork(pthread);
	present_time = now_time();
	print_philo_msg(present_time - loop_info.start_time, \
					pthread->p_num + 1, EatMsg);
	vsleep((unsigned int)g_argv_info.eat); // 200 while(0 -> 200) sleep(1);
	if (present_time - last_time < g_argv_info.die)
	{
		last_time = now_time();
		pthread->last_eat_time = last_time;
	}
	else
	{
		return (_ERROR);
	}
	philo_has_unfork(pthread);

	return (_OK);
}
