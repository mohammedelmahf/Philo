/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 18:56:28 by maelmahf          #+#    #+#             */
/*   Updated: 2025/06/02 09:56:21 by maelmahf         ###   ########.fr       */
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

# define RESET    "\033[0m"
# define RED      "\033[31m"    /* Red */
# define GREEN    "\033[32m"    /* Green */

typedef pthread_t		t_id;
typedef pthread_mutex_t	t_mutex;
typedef struct timeval	t_timeval;

typedef struct s_mutexes
{
	t_mutex	*left_fork;
	t_mutex	*right_fork;
	t_mutex	*write_lock;
	t_mutex	*meal_lock;
}	t_mutexes;

typedef struct s_times
{
	size_t	die;
	size_t	eat;
	size_t	sleep;
	size_t	last_meal;
	size_t	born_time;
}	t_times;

typedef struct s_philo
{
	int				id;
	t_mutexes		mutexes;
	int				must_eat;
	t_id			thread_id;
	int				meal_eaten;
	int				philo_count;
	t_times			times;
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
void init_engine(t_engine *engine , t_philo *philos , t_mutex *forks);
void init_forks(t_engine *engine, t_mutex *forks, int count);
void    launcher(t_engine *engine, int count);
void    *observer(void *ptr);
void	destroy_all(t_engine *engine, char *str, int count, int signal);
void    init_philos(t_engine *engine, t_philo *philos, t_mutex *forks, char **av);
// int error_msg(char *msg ,t_params *args,t_philo *p ,  int malloc);





//utils
int	is_number(const char *str);
int	ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
int	ft_isdigit(int c);
#endif