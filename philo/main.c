/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:58:36 by maelmahf          #+#    #+#             */
/*   Updated: 2025/06/11 14:02:31 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_threads(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->nbr_philo)
	{
		program->philos[i].last_meal_time = program->start_time;
		if (pthread_create(&program->philos[i].thread, NULL, philo_routine,
				&program->philos[i]) != 0)
			printf("Error: Failed to create thread for philosopher %d\n", i
				+ 1);
		i++;
	}
}

int	start_simulation(t_program *program)
{
	pthread_t	monitor;
	int			i;

	create_threads(program);
	if (pthread_create(&monitor, NULL, death_monitor, program) != 0)
	{
		printf("Error: Failed to create monitor thread\n");
		return (1);
	}
	pthread_join(monitor, NULL);
	i = 0;
	while (i < program->nbr_philo)
		pthread_join(program->philos[i++].thread, NULL);
	return (0);
}

int	main(int ac, char **av)
{
	t_program	program;

	memset(&program, 0, sizeof(t_program));
	if (!parse_program(ac, av, &program))
		return (1);
	if (init_mutexes(&program) || init_philosophers(&program))
	{
		printf("Error: Initialization failed\n");
		clear_all(&program);
		return (1);
	}
	if (program.count_eat != 0)
		start_simulation(&program);
	clear_all(&program);
	return (0);
}
