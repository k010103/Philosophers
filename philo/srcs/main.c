/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 21:26:57 by junmkang          #+#    #+#             */
/*   Updated: 2021/07/04 19:48:13 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int	main(int argc, char **argv)
{
	t_info	info;

	memset(&info, 0, sizeof(info));
	if ((info_init(&info, argc, argv)))
		return (_ERROR);
	if ((philo_setup(&info)))
		return (_ERROR);
	if ((philo_loop(&info)))
		return (_ERROR);
	if ((philo_free(&info)))
		return (_ERROR);
	return (_OK);
}
