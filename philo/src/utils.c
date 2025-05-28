/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:02:27 by maelmahf          #+#    #+#             */
/*   Updated: 2025/05/28 11:27:52 by maelmahf         ###   ########.fr       */
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

void error_msg(char *text, int signal)
{
    if(text)
        write(2,text , ft_strlen(text) + 1);
    exit(signal);
}

void	print_action(t_philo *philo, char *action)
{
	size_t	time;

	pthread_mutex_lock(philo->mutexes.write_lock);
	time = get_current_time() - philo->times.born_time;
	printf(GREEN"[%ld]"RESET" %d%s\n", time, philo->id, action);
	pthread_mutex_unlock(philo->mutexes.write_lock);
}