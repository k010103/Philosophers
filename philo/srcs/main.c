/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 21:26:57 by junmkang          #+#    #+#             */
/*   Updated: 2021/06/29 18:02:44 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"


int		value_type_check(char **str)
{
	int		x;
	int		y;

	x = 0;
	y = 1;
	while (str[y])
	{
		x = 0;
		while (str[y][x])
		{
			if (!('0' <= str[y][x] && str[y][x] <= '9'))
				return (_ERROR);
			x++;
		}
		y++;
	}
	return (_OK);
}

int		value_check(char **str, t_info *g_argv_info, int argc)
{
	if ((value_type_check(str)))
		return (_ERROR);
	g_argv_info->philo_num = ft_atoi(str[1]);
	g_argv_info->die = ft_atoi(str[2]);
	g_argv_info->eat = ft_atoi(str[3]);
	g_argv_info->sleep = ft_atoi(str[4]);
	if (argc == 6)
		g_argv_info->must_eat = ft_atoi(str[5]);
	return (_OK);
}

int	main(int argc, char **argv)
{
	t_philo		philos;

	if (!(argc == 5 || argc == 6))
		return (print_error_msg("Invalid number. : 4 or 5"));
	if ((value_check(argv, &g_argv_info, argc)))
		return (print_error_msg("Invalid value."));

	philo_setup(&philos);
	return (_OK);
}
