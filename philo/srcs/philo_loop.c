/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:19:18 by junmkang          #+#    #+#             */
/*   Updated: 2021/06/30 22:24:07 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

/*
** int		int_test(int *test)
** {
** 	int		count;

** 	count = 0;
** 	while (count < info->philo_num)
** 	{
** 		*test++ = count + 1;
** 		count++;
** 	}
** 	return (_OK);
** }


** int		test(void)
** {
** 	struct timeval    my_time;
**     gettimeofday(&my_time, NULL);
**     printf("time : %ld\n", my_time.tv_sec);
**     printf("macro time : %d\n", my_time.tv_usec);

** 	return (_OK);
** }

** (eating -> sleeping -> thinking)
** 먹고 자고 생각.
*/

void		*philo_action(void *v_pthread)
{
	t_pthread		*pthread;

	pthread = (t_pthread *)v_pthread;
	pthread->last_eat_time = now_time();
	while (1)
	{
		if ((philo_eat(pthread)))
			philo_die(pthread);
		philo_sleep(pthread);
		philo_think(pthread);
	}
}

int				philo_loop(t_philo *philos)
{
	int			count;

	count = 0;
	while(count < g_argv_info.philo_num)
	{
		philos->pthread[count].p_num = count;
		pthread_create(&philos->pthread[count].philo, \
						NULL, philo_action, (void *)&(philos->pthread[count]));
		count++;
	}

	return (_OK);
}

