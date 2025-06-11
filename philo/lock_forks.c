/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:58:40 by maelmahf          #+#    #+#             */
/*   Updated: 2025/06/11 14:04:04 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	lock_single_fork(t_philo *philo, pthread_mutex_t *fork)
{
	if (check_simulation_end(philo->program))
		return (0);
	pthread_mutex_lock(fork);
	if (check_simulation_end(philo->program))
	{
		pthread_mutex_unlock(fork);
		return (0);
	}
	print_action(philo, "has taken a fork");
	return (1);
}

int	take_forks(t_philo *philo)
{
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;

	first = philo->l_fork;
	second = philo->r_fork;
	if (philo->id % 2 != 0)
	{
		first = philo->r_fork;
		second = philo->l_fork;
	}
	if (!lock_single_fork(philo, first))
		return (0);
	if (philo->program->nbr_philo == 1)
	{
		ft_sleep(philo->program->die_time * 1000, philo);
		pthread_mutex_unlock(first);
		return (0);
	}
	if (!lock_single_fork(philo, second))
	{
		pthread_mutex_unlock(first);
		return (0);
	}
	return (1);
}

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}
