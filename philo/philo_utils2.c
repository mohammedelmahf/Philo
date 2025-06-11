/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:58:13 by maelmahf          #+#    #+#             */
/*   Updated: 2025/06/11 14:03:18 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	check_simulation_end(t_program *program)
{
	int	ended;

	pthread_mutex_lock(&program->death_lock);
	ended = program->is_dead;
	pthread_mutex_unlock(&program->death_lock);
	return (ended);
}

int	check_argument(char *av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!ft_isdigit(av[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_sleep(long long time, t_philo *philo)
{
	long long	start;

	time /= 1000;
	start = get_time();
	while ((get_time() - start) < time)
	{
		if (check_simulation_end(philo->program))
			break ;
		usleep(100);
	}
}

void	clear_all(t_program *program)
{
	int	i;

	if (!program)
		return ;
	if (program->philos)
		free(program->philos);
	if (program->forks && program->meal_locks && program->meals_eaten_locks
		&& program->last_meal_time_locks)
	{
		i = 0;
		while (i < program->nbr_philo)
		{
			pthread_mutex_destroy(&program->forks[i]);
			pthread_mutex_destroy(&program->meal_locks[i]);
			pthread_mutex_destroy(&program->meals_eaten_locks[i]);
			pthread_mutex_destroy(&program->last_meal_time_locks[i]);
			i++;
		}
		free(program->forks);
		free(program->meal_locks);
		free(program->meals_eaten_locks);
		free(program->last_meal_time_locks);
	}
	pthread_mutex_destroy(&program->print_lock);
	pthread_mutex_destroy(&program->death_lock);
}
