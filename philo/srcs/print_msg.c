/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 23:56:34 by junmkang          #+#    #+#             */
/*   Updated: 2021/06/28 21:08:49 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int		print_error_msg(char *str)
{
	write(1, str, ft_strlen(str));
	return (_ERROR);
}

int		print_philo_msg(char *str)
{
	write(1, str, ft_strlen(str));
	return (_OK);
}
