/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 20:38:35 by junmkang          #+#    #+#             */
/*   Updated: 2021/07/02 17:41:37 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int			philo_think(t_philo *philo)
{
	print_philo_msg(philo, ThinkMsg);
	return (_OK);
}
