/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 20:38:35 by junmkang          #+#    #+#             */
/*   Updated: 2021/06/30 22:23:29 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int			philo_think(t_pthread *pthread)
{
	long long	present_time;

	present_time = now_time();
	print_philo_msg(present_time - loop_info.start_time, \
					pthread->p_num + 1, ThinkMsg);
	return (_OK);
}
