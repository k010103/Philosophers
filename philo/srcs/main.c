/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 21:26:57 by junmkang          #+#    #+#             */
/*   Updated: 2021/06/22 02:39:49 by junmkang         ###   ########.fr       */
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
			{
				printf("test = %s\n", str[y]);
				printf("test = %c\n", str[y][x]);
				return (_ERROR);
			}
			x++;
		}
		y++;
	}
	return (_OK);
}

int		value_check(char **str, t_info *info, int argc)
{
	if (!value_type_check(str))
		return (_ERROR);
	info->philo_num = ft_atoi(str[1]);
	info->die = ft_atoi(str[2]);
	info->eat = ft_atoi(str[3]);
	info->sleep = ft_atoi(str[4]);
	if (argc == 6)
		info->must_eat = ft_atoi(str[5]);
	return (_OK);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (!(argc == 5 || argc == 6))
		return (print_error_msg("Invalid count."));
	if (!(value_check(argv, &info, argc)))
		return (print_error_msg("Invalid value."));

	argc++;
	argv++;
	printf("test");
	return (_OK);
}
