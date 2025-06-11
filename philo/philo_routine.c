/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:58:23 by maelmahf          #+#    #+#             */
/*   Updated: 2025/06/11 14:46:41 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_philo *philo, char *action)
{
	pthread_mutex_lock(&philo->program->print_lock);
	if (check_simulation_end(philo->program))
	{
		pthread_mutex_unlock(&philo->program->print_lock);
		return ;
	}
	printf(GREEN"[%lld]"RESET" %d %s\n",
		get_time() - philo->program->start_time,
		philo->id,
		action);
	pthread_mutex_unlock(&philo->program->print_lock);
}

void	handle_one_philosopher(t_philo *philo)
{
	long	start_time;

	start_time = get_time();
	print_action(philo, "has taken a fork");
	ft_sleep(philo->program->die_time * 1000, philo);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->program->nbr_philo == 1)
	{
		handle_one_philosopher(philo);
		return (NULL);
	}
	while (1)
	{
		if (philo->id % 2 == 0)
			usleep(500);
		if (philo->program->nbr_philo < 100)
			usleep(200);
		if (!philo_eat(philo))
			break ;
		if (philosopher_finished_meals(philo))
			break ;
		if (!philo_sleep(philo))
			break ;
		if (!philo_think(philo))
			break ;
	}
	return (NULL);
}
