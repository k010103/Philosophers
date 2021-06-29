/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 21:35:15 by junmkang          #+#    #+#             */
/*   Updated: 2021/06/29 22:48:58 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int			philo_join(t_philo *philos)
{
	int		count;

	count = 0;
	while (count < g_argv_info.philo_num)
	{
		pthread_join(philos->pthread[count % 2].philo, NULL);
		count++;
	}
	return (_OK);
}
