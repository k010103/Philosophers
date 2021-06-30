/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_die.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:37:23 by junmkang          #+#    #+#             */
/*   Updated: 2021/06/30 22:22:53 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int			philo_die(t_pthread *pthread)
{
	long long	present_time;

	present_time = now_time();
	print_philo_msg(present_time - loop_info.start_time, pthread->p_num + 1, DiedMsg);
	exit(0);
	return (_OK);
}
