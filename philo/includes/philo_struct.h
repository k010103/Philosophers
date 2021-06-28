/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 02:08:21 by junmkang          #+#    #+#             */
/*   Updated: 2021/06/28 21:57:13 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef PHILO_STRUCT_H
#	define PHILO_STRUCT_H

/*
**
*/

typedef struct				s_philo
{
	pthread_t				philo;
	pthread_mutex_t			fork;
	t_philo_current_info	cp_info;
	t_info					gv_info;
}							t_philo;

/*
** 입력값.
*/

typedef struct				s_info
{
	int						philo_num;
	int						die;
	int						eat;
	int						sleep;
	int						must_eat;
}							t_info;

/*
**
*/

typedef struct				s_philo_current_info
{
	struct timeval			last_eat_time;

}							t_philo_current_info;


#	endif
