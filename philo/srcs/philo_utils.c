/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:29:33 by junmkang          #+#    #+#             */
/*   Updated: 2021/06/29 23:14:19 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

// 현재시간 가져오기.
int		get_current_time(int elapse)
{
	struct timeval	start;
	struct timeval	end;

	gettimeofday(&start, NULL);
    usleep(elapse);
    gettimeofday(&end, NULL);

    int seconds  = end.tv_sec  - start.tv_sec;
    int useconds = end.tv_usec - start.tv_usec;
	printf("info->eat = %d\n", elapse);
	printf("seconds = %d\n", seconds);
	printf("useconds = %d\n", useconds);
	return (_OK);
}

static int	vsleep_usec(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_usec);
}

void	vsleep(unsigned int time)
{
	unsigned int	finish_time;

	finish_time = time + vsleep_usec();
	while(finish_time > vsleep_usec())
	{usleep(100);}
}
