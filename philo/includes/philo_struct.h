/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 02:08:21 by junmkang          #+#    #+#             */
/*   Updated: 2021/06/29 22:40:06 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef PHILO_STRUCT_H
#	define PHILO_STRUCT_H


typedef enum				e_msg
{
	ForkMsg = 0,
	EatMsg,
	SleepMsg,
	ThinkMsg,
	DiedMsg
}							t_msg;

/*
** philo에 대한 정보들.
*/

typedef struct				s_pthread
{
	pthread_t				philo;
	struct timeval			last_eat_time;
	int						p_num;

}							t_pthread;


/*
** (global)
*/

typedef struct				s_info
{
	int						philo_num;
	int						die;
	int						eat;
	int						sleep;
	int						must_eat;
	struct timeval			start_time;
	pthread_mutex_t			mutex_text;
	pthread_mutex_t			*fork;
}							t_info;

/*
** philo (가장 큰 구조체)
*/

typedef struct				s_philo
{
	t_pthread				*pthread;
}							t_philo;

#	endif
