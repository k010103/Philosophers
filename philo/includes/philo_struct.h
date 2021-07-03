/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 02:08:21 by junmkang          #+#    #+#             */
/*   Updated: 2021/07/03 18:02:38 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef PHILO_STRUCT_H
#	define PHILO_STRUCT_H

typedef struct				s_philo
{
	pthread_t				thread;
	long long				last_eat_time;
	pthread_mutex_t			*r_fork;
	pthread_mutex_t			*l_fork;
	int						p_ptr;
	struct s_info			*info;
	int						eaten_num;
}							t_philo;

typedef struct				s_info
{
	int						philo_num;
	int						die;
	int						eat;
	int						sleep;
	int						must_eat;
	long long				start_time;
	int						die_or_life;
	int						it_one;
	pthread_mutex_t			mutex_text;
	pthread_mutex_t			*forks;
	t_philo					*philos;
}							t_info;

/*
** typedef struct s_info t_info;

** typedef struct				s_philo
** {
** 	pthread_t				thread;
** 	long long				last_eat_time;
** 	pthread_mutex_t			*r_fork;
** 	pthread_mutex_t			*l_fork;
** 	int						p_ptr;
** 	t_info					*info;
** }							t_philo;

** struct						s_info
** {
** 	int						philo_num;
** 	int						die;
** 	int						eat;
** 	int						sleep;
** 	int						must_eat;
** 	long long				start_time;
** 	pthread_mutex_t			mutex_text;
** 	pthread_mutex_t			*forks;
** 	t_philo					*philos;
** };
*/

#	endif
