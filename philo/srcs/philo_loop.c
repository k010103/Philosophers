/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:19:18 by junmkang          #+#    #+#             */
/*   Updated: 2021/07/02 17:46:22 by junmkang         ###   ########.fr       */
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
	t_philo		*philo;

	philo = (t_philo *)v_pthread;
	philo->last_eat_time = now_time();
	while (1)
	{
		philo_forks(philo);
		if ((philo_eat(philo)))
			philo_die(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
}

int			create_philos(t_info *info)
{
	int		count;

	count = 0;
	while(count < info->philo_num)
	{
		pthread_create(&info->philos[count].thread, \
						NULL, philo_action, (void *)&info->philos[count]);
		count++;
	}
	return (_OK);
}

int				philo_loop(t_info *info)
{
	create_philos(info);
	return (_OK);
}

