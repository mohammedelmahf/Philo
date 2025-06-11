/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:50:11 by maelmahf          #+#    #+#             */
/*   Updated: 2025/06/11 14:08:24 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>

# define RESET "\033[0m"
# define RED "\033[31m"   /* Red */
# define GREEN "\033[32m" /* Green */

typedef struct s_program
{
	long			nbr_philo;
	long			die_time;
	long			eat_time;
	long			sleep_time;
	long			count_eat;
	long long		start_time;
	int				is_dead;
	int				flag;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*meal_locks;
	pthread_mutex_t	*meals_eaten_locks;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	death_lock;
	pthread_mutex_t	*last_meal_time_locks;
	struct s_philo	*philos;
}					t_program;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	int				check;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*meal_lock;
	pthread_mutex_t	*meals_eaten_locks;
	pthread_mutex_t	*last_meal_time_lock;
	long long		last_meal_time;
	int				meals_eaten;
	t_program			*program;
}					t_philo;

int					ft_atoi(char *str, t_program *args);
long				get_time(void);
void				clear_all(t_program *program);
int					check_simulation_end(t_program *program);
void				ft_sleep(long long time, t_philo *philo);
int					ft_isdigit(int c);
void				*philo_routine(void *arg);
void				eat(t_philo *philo);
void				print_action(t_philo *philo, char *action);
void				handle_one_philosopher(t_philo *philo);
int					parse_program(int ac, char **av, t_program *args);
int					init_mutexes(t_program *program);
int					init_philosophers(t_program *program);
int					philosopher_finished_meals(t_philo *philo);
void				*death_monitor(void *arg);
int					start_simulation(t_program *program);
int					philo_sleep(t_philo *philo);
int					philo_eat(t_philo *philo);
int					philo_think(t_philo *philo);
int					check_philo_died(t_philo *philo);
int					take_forks(t_philo *philo);
void				release_forks(t_philo *philo);
int					philo_died(t_philo *philo);
#endif
