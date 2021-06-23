/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:19:18 by junmkang          #+#    #+#             */
/*   Updated: 2021/06/24 00:07:23 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int		allocate_junmkang(t_philo *philo, t_info *info)
{
	int		count;

	count = 0;
	while (count < info->philo_num)
	{
		printf("count : %d\n", count);
		if ((pthread_mutex_init(&(philo[count].fork), NULL)))
			return (_ERROR);
		count++;
	}
	return (_OK);
}

// int		int_test(int *test, t_info *info)
// {
// 	int		count;

// 	count = 0;
// 	while (count < info->philo_num)
// 	{
// 		*test++ = count + 1;
// 		count++;
// 	}
// 	return (_OK);
// }

// int		philo_loop(t_info *info)
// {
// 	return (_OK);
// }

int		philo_setup(t_info *info)
{
	t_philo				*philo;
	// int					*test;

	philo = ft_malloc(sizeof(t_philo) * info->philo_num);
	// test = ft_malloc(sizeof(int) * info->philo_num);

	allocate_junmkang(philo, info);
	// int_test(test, &info);
	// printf("philo_num = %d\n", info.philo_num);
	// philo_loop();
	printf("ok malloc");
	return (_OK);
}
