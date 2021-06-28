/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:19:18 by junmkang          #+#    #+#             */
/*   Updated: 2021/06/28 23:13:58 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int		allocate_fork_junmkang(t_philo *philo)
{
	int		count;

	count = 0;
	while (count < philo->argv_info.philo_num)
	{
		// printf("count : %d\n", count);
		if ((pthread_mutex_init(&(philo->pthread[count].fork), NULL)))
			return (_ERROR);
		count++;
	}
	return (_OK);
}

/*
** int		int_test(int *test, t_info *info)
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

*/

int		test(void)
{
	struct timeval    my_time;
    gettimeofday(&my_time, NULL);
    printf("time : %ld\n", my_time.tv_sec);
    printf("macro time : %d\n", my_time.tv_usec);

	return (_OK);
}

// (eating -> sleeping -> thinking)
// 먹고 자고 생각.
int		philo_loop(t_philo *philo, t_info *info)
{
	int		ptr;

	while (1)
	{
		ptr = 0;
		while (ptr < info->philo_num)
		{
			if (!(philo_eat(info, philo, info->philo_num)))
				philo_die(info, philo, info->philo_num);
			philo_sleep(info, philo, info->philo_num);
			philo_think(info, philo, info->philo_num);
			ptr++;
		}
	}
	return (_OK);
}

int		philo_setup(t_philo *philo)
{
	int					count;

	count = 0;
	philo->pthread = ft_malloc(sizeof(philo->pthread) * philo->argv_info.philo_num);
	allocate_fork_junmkang(philo);
	// int_test(test, &info);
	// printf("philo_num = %d\n", info.philo_num);

	// while(count < info->philo_num)
	// {
	// 	pthread_create(&philo, NULL, philo_loop, (void *)&count);
	// 	count++;
	// }
	return (_OK);
}
