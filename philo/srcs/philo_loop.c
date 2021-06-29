/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:19:18 by junmkang          #+#    #+#             */
/*   Updated: 2021/06/29 21:25:37 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

/*
** int		int_test(int *test)
** {
** 	int		count;

** 	count = 0;
** 	while (count < info->philo_num)
** 	{
** 		*test++ = count + 1;
** 		count++;
** 	}
** 	return (_OK);
** }


** int		test(void)
** {
** 	struct timeval    my_time;
**     gettimeofday(&my_time, NULL);
**     printf("time : %ld\n", my_time.tv_sec);
**     printf("macro time : %d\n", my_time.tv_usec);

** 	return (_OK);
** }

** (eating -> sleeping -> thinking)
** 먹고 자고 생각.
*/

void			philo_initial_value(t_pthread *pthread)
{
	struct timeval	temp;

	gettimeofday(&temp, NULL);
	pthread->last_eat_time = temp;
}

static void		philo_action(void *v_pthread)
{
	t_pthread		*pthread;

	pthread = (t_pthread *)v_pthread;
	philo_initial_value(pthread);
	// printf("%d\n", pthread.p_num);
	// printf("%d\n", *(t_philo *)v_philo)
	while (1)
	{
		philo_eat(pthread);
		// if (!(philo_eat(&philo, philo.pthread->philo)))
		// 	philo_die(philo, philo.pthread->philo);
		// philo_sleep(philo, philo.pthread->philo);
		// philo_think(philo, philo.pthread->philo);
	}
}

int				philo_free_join(t_philo *philos)
{
	int		count;
	void	*ret;

	count = 0;
	while (count < g_argv_info.philo_num)
	{
		pthread_join(philos->pthread[count].philo, &ret);
		count++;
	}
	return (_OK);
}

int				philo_loop(t_philo *philos)
{
	int			count;

	gettimeofday(&g_argv_info.start_time, NULL);
	count = 0;
	while(count < g_argv_info.philo_num)
	{
		philos->pthread[count].p_num = count;
		// printf("%d\n", philos->pthread[count].p_num);
		pthread_create(&philos->pthread[count].philo, \
						NULL, philo_action, (void *)&(philos->pthread[count]));
		count++;
	}

	return (_OK);
}

