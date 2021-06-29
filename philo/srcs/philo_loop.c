/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:19:18 by junmkang          #+#    #+#             */
/*   Updated: 2021/06/29 18:17:53 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int		allocate_fork_junmkang(t_philo *philo)
{
	int		count;

	count = 0;
	while (count < g_argv_info.philo_num)
	{
		// printf("count : %d\n", count);
		if ((pthread_mutex_init(&(philo->pthread[count].fork), NULL)))
			return (_ERROR);
		count++;
	}
	return (_OK);
}

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

void	philo_action(void *v_pthread)
{
	t_pthread		*pthread;

	pthread = (t_pthread *)v_pthread;
	// printf("%d\n", pthread.p_num);
	// printf("%d\n", *(t_philo *)v_philo)
	philo_eat(pthread);
	// if (!(philo_eat(&philo, philo.pthread->philo)))
	// 	philo_die(philo, philo.pthread->philo);
	// philo_sleep(philo, philo.pthread->philo);
	// philo_think(philo, philo.pthread->philo);
}

int		philo_loop(t_philo *philos)
{
	int			count;

	// printf("%lu %lu\n", sizeof(void *), sizeof(t_philo *));
	while (1)
	{
		gettimeofday(&g_argv_info.start_time, NULL);
		count = 0;
		while(count < g_argv_info.philo_num)
		{
			philos->pthread[count].p_num = count;
			// printf("%d\n", philos->pthread[count].p_num);
			pthread_create(&philos->pthread[0].philo, NULL, philo_action, (void *)&(philos->pthread[0]));
			count++;
		}
	}

	return (_OK);
}

int		philo_setup(t_philo *philos)
{
	philos->pthread = ft_malloc(sizeof(philos->pthread) * g_argv_info.philo_num);

	allocate_fork_junmkang(philos);
	philo_loop(philos);
	// int_test(test, &info);
	// printf("philo_num = %d\n", philo->g_argv_info.philo_num);

	return (_OK);
}
