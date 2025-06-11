/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:58:44 by maelmahf          #+#    #+#             */
/*   Updated: 2025/06/11 14:04:19 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	allocate_mutexes(t_program *program)
{
	program->forks = malloc(sizeof(pthread_mutex_t) * program->nbr_philo);
	program->meal_locks = malloc(sizeof(pthread_mutex_t) * program->nbr_philo);
	program->meals_eaten_locks = malloc(sizeof(pthread_mutex_t)
			* program->nbr_philo);
	program->last_meal_time_locks = malloc(sizeof(pthread_mutex_t)
			* program->nbr_philo);
	if (!program->forks || !program->meal_locks
		|| !program->meals_eaten_locks || !program->last_meal_time_locks)
		return (1);
	return (0);
}

int	init_mutexes(t_program *program)
{
	int	i;

	if (allocate_mutexes(program))
		return (1);
	i = 0;
	while (i < program->nbr_philo)
	{
		if (pthread_mutex_init(&program->last_meal_time_locks[i], NULL)
			|| pthread_mutex_init(&program->forks[i], NULL)
			|| pthread_mutex_init(&program->meal_locks[i], NULL)
			|| pthread_mutex_init(&program->meals_eaten_locks[i], NULL))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&program->print_lock, NULL)
		|| pthread_mutex_init(&program->death_lock, NULL))
		return (1);
	return (0);
}

int	init_philosophers(t_program *program)
{
	int		i;
	t_philo	*philo;

	program->philos = malloc(sizeof(t_philo) * program->nbr_philo);
	if (!program->philos)
		return (1);
	program->start_time = get_time();
	program->is_dead = 0;
	i = 0;
	while (i < program->nbr_philo)
	{
		philo = &program->philos[i];
		philo->id = i + 1;
		philo->program = program;
		philo->meals_eaten = 0;
		philo->check = 0;
		philo->last_meal_time = program->start_time;
		philo->l_fork = &program->forks[i];
		philo->r_fork = &program->forks[(i + 1) % program->nbr_philo];
		program->philos[i].last_meal_time_lock = &program->last_meal_time_locks[i];
		philo->meal_lock = &program->meal_locks[i];
		i++;
	}
	return (0);
}
