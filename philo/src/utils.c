/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:02:27 by maelmahf          #+#    #+#             */
/*   Updated: 2025/06/03 11:05:54 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

// int error_msg(char *msg ,t_params *args,t_philo *p ,  int malloc)
// {
//     if(malloc)
//     {
//         if(args->death)
//             free(args->death);
//         if(args->fork)
//             free(args->fork);
//         if(p)
//             free(p);
//     }
//     return(printf("%s" , msg));
// }

void	destroy_all(t_engine *engine, char *str, int count, int signal)
{
	while(--count >= 0)
		pthread_mutex_destroy(&engine->forks[count]);
	pthread_mutex_destroy(&engine->write_lock);
	pthread_mutex_destroy(&engine->meal_lock);
	error_msg(str , signal);
}

void error_msg(char *text, int signal)
{
    if(text)
        write(2,text , ft_strlen(text) + 1);
    exit(signal);
}

void	ft_usleep(size_t mls)
{
	size_t	start;

	start = get_current_time();
	while (get_current_time() - start < mls)
		usleep(500);
}

void	print_action(t_philo *philo, char *action)
{
	size_t	time;

	pthread_mutex_lock(philo->mutexes.write_lock);
	time = get_current_time() - philo->times.born_time;
	printf(GREEN"[%ld]"RESET" %d%s\n", time, philo->id, action);
	pthread_mutex_unlock(philo->mutexes.write_lock);
}

size_t	get_current_time(void)
{
	t_timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		error_msg("[gettimeofday ERROR]\n", 1);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}