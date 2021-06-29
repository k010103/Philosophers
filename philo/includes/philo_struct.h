/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 02:08:21 by junmkang          #+#    #+#             */
/*   Updated: 2021/06/29 17:48:13 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef PHILO_STRUCT_H
#	define PHILO_STRUCT_H

/*
** philo에 대한 정보들.
*/

typedef struct				s_pthread
{
	pthread_t				philo;
	pthread_mutex_t			fork;
	struct timeval			last_eat_time;
	int						p_num;

}							t_pthread;


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
	struct timeval			start_time;
}							t_info;

/*
** philo (가장 큰 구조체)
*/

typedef struct				s_philo
{
	t_pthread				*pthread;
}							t_philo;

#	endif
