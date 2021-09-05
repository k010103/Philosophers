/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 16:36:42 by junmkang          #+#    #+#             */
/*   Updated: 2021/07/04 23:12:10 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "philo.h"

int	value_type_check(char **argv)
{
	int		x;
	int		y;

	x = 0;
	y = 1;
	while (argv[y])
	{
		x = 0;
		while (argv[y][x])
		{
			if (!('0' <= argv[y][x] && argv[y][x] <= '9'))
				return (_ERROR);
			x++;
		}
		y++;
	}
	return (_OK);
}

int	value_check(t_info *info, int argc, char **argv)
{
	if ((value_type_check(argv)))
		return (_ERROR);
	info->philo_num = ft_atoi(argv[1]);
	info->die = ft_atoi(argv[2]);
	info->eat = ft_atoi(argv[3]);
	info->sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->must_eat = ft_atoi(argv[5]);
	return (_OK);
}

int	info_init(t_info *info, int argc, char **argv)
{
	if (!(argc == 5 || argc == 6))
		return (print_error_msg("Invalid number. : 4 or 5\n"));
	if ((value_check(info, argc, argv)))
		return (print_error_msg("Invalid value.\n"));
	if (info->philo_num >= 201)
		return (print_error_msg("too many philo : error\nn < 200\n"));
	return (_OK);
}
