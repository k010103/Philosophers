/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 21:35:15 by junmkang          #+#    #+#             */
/*   Updated: 2021/07/04 20:06:46 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int			philo_join(t_info *info)
{
	int		count;

	count = 0;
	while (count < info->philo_num)
	{
		if ((pthread_join(info->philos[count].thread, NULL)))
			return (_ERROR);
		count++;
	}
	return (_OK);
}

int			fork_destroy(t_info *info)
{
	int		count;

	count = 0;
	while (count < info->philo_num)
	{
		if ((pthread_mutex_destroy(&info->forks[count])))
			return (_ERROR);
		count++;
	}
	return (_OK);
}

int			philo_free(t_info *info)
{
	if ((philo_join(info)))
		return (print_error_msg("philo_join : error\n"));
	if ((fork_destroy(info)))
		return (print_error_msg("fork_destroy : error\n"));
	if (info->must_eat)
		printf("%s\n", END_EAT);
	return (_OK);
}
