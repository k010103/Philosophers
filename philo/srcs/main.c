/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 21:26:57 by junmkang          #+#    #+#             */
/*   Updated: 2021/06/28 22:45:31 by junmkang         ###   ########.fr       */
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

int		value_check(char **str, t_info *argv_info, int argc)
{
	if ((value_type_check(str)))
		return (_ERROR);
	argv_info->philo_num = ft_atoi(str[1]);
	argv_info->die = ft_atoi(str[2]);
	argv_info->eat = ft_atoi(str[3]);
	argv_info->sleep = ft_atoi(str[4]);
	if (argc == 6)
		argv_info->must_eat = ft_atoi(str[5]);
	return (_OK);
}

int	main(int argc, char **argv)
{
	t_philo		philo;

	if (!(argc == 5 || argc == 6))
		return (print_error_msg("Invalid number. : 4 or 5"));
	if ((value_check(argv, &philo.argv_info, argc)))
		return (print_error_msg("Invalid value."));

	philo_setup(&philo);
	return (_OK);
}
