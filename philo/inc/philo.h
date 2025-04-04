/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 18:56:28 by maelmahf          #+#    #+#             */
/*   Updated: 2025/04/04 18:27:07 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H


#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
# include <pthread.h>
typedef struct s_philo
{
    
}     t_philo;

typedef struct s_params
{
    int num;
    int t2d;
    int t2e;
    int t2s;
    int ready;
    int				max_iter;
	int				check_meal;
	int				over;
	long int		start;
	pthread_mutex_t	*death;
	pthread_mutex_t	*fork;
    
}       t_params;


int     init_args(t_params *p, char **av);
int error_msg(char *msg ,t_params *args,t_philo *p ,  int malloc);
int	ft_atoi(const char *str);

#endif