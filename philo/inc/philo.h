/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 18:56:28 by maelmahf          #+#    #+#             */
/*   Updated: 2025/05/15 13:04:44 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H


#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
# include <pthread.h>
#include <unistd.h>

# define PHILO_MAX_COUNT 200
# define PHILO_MAX_TIME 1000000

typedef pthread_t		t_id;
typedef pthread_mutex_t	t_mutex;
typedef struct timeval	t_timeval;

typedef struct s_philo
{
    
}     t_philo;

typedef struct  s_engine
{
	t_mutex	*forks;
	t_philo	*philos;
	t_mutex	meal_lock;
	t_mutex	write_lock;
}               t_engine;

// typedef struct s_params
// {
//     int num;
//     int t2d;
//     int t2e;
//     int t2s;
//     int ready;
//     int				max_iter;
// 	int				check_meal;
// 	int				over;
// 	long int		start;
// 	pthread_mutex_t	*death;
// 	pthread_mutex_t	*fork;
    
// }       t_params;


// int     init_args(t_params *p, char **av);
void error_msg(char *text, int signal);
void check_args(int ac, char **av);
void check_engine(t_engine *engine , t_philo *philos , t_mutex *forks);
// int error_msg(char *msg ,t_params *args,t_philo *p ,  int malloc);





//utils
int	is_number(const char *str);
int	ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
int	ft_isdigit(int c);
#endif