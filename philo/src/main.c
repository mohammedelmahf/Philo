/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 18:58:40 by maelmahf          #+#    #+#             */
/*   Updated: 2025/05/28 11:15:59 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	check_args(int ac, char **av)
{
	int		i;
	long	num;

	i = 0;
	if (ac < 5 || ac > 6)
		error_msg("Error: Wrong number of arguments\n", 1);
	while (++i < ac)
	{
		num = ft_atoi(av[i]);
		if (!is_number(av[i]))
			error_msg("Error: Argument Not Numeric ERROR\n", 1);
		else if (i == 1 && (num < 1 || num > PHILO_MAX_COUNT))
			error_msg("Error: Argument Error\n", 1);
		else if (i == 5 && (num < 0 || num > INT_MAX))
			error_msg("Error: Argument Error\n", 1);
		else if (i != 5 && i != 1 && (num < 0 || num > INT_MAX))
			error_msg("Error: Argument Error\n", 1);
	}
}

int	main(int ac, char **av)
{
	t_philo philos[PHILO_MAX_COUNT];
	t_mutex forks[PHILO_MAX_COUNT];
	t_engine engine;

	check_args(ac, av);
	init_engine(&engine, philos, forks);
	init_forks(&engine, forks, ft_atoi(av[1]));
	init_philos(&engine, philos, forks, av);
	launcher(&engine, philos[0].philo_count);
}