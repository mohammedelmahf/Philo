/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:58:30 by maelmahf          #+#    #+#             */
/*   Updated: 2025/06/11 14:03:55 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_and_handle_death(t_program *program, t_philo *philo)
{
	int	is_checking;

	pthread_mutex_lock(philo->meal_lock);
	is_checking = philo->check;
	pthread_mutex_unlock(philo->meal_lock);
	if (!is_checking && philo_died(philo))
	{
		pthread_mutex_lock(&program->death_lock);
		program->is_dead = 1;
		pthread_mutex_unlock(&program->death_lock);
		pthread_mutex_lock(&program->print_lock);
		printf("%lld %d died\n", get_time() - program->start_time, philo->id);
		pthread_mutex_unlock(&program->print_lock);
		return (1);
	}
	return (0);
}

static int	philos_running(t_program *program)
{
	int	i;
	int	philos_done;

	i = 0;
	philos_done = 0;
	while (i < program->nbr_philo)
	{
		if (philosopher_finished_meals(&program->philos[i]))
			philos_done++;
		else if (check_and_handle_death(program, &program->philos[i]))
			return (0);
		i++;
	}
	return (philos_done != program->nbr_philo);
}

void	*death_monitor(void *arg)
{
	t_program	*program;

	program = (t_program *)arg;
	while (get_time() < program->start_time)
		usleep(250);
	usleep(program->die_time * 1000);
	while (philos_running(program))
		usleep(500);
	return (NULL);
}
