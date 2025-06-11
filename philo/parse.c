/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:09:34 by maelmahf          #+#    #+#             */
/*   Updated: 2025/06/11 14:09:40 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	validate_args_numbers(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!is_number(av[i]))
		{
			printf("Error: Argument %d is not a valid number: %s\n", i, av[i]);
			return (0);
		}
		i++;
	}
	return (1);
}

int	validate_args_values(t_program *args, int ac)
{
	if (args->nbr_philo <= 0)
		return (printf("Error: Number of philosophers must be > 0\n"), 0);
	if (args->die_time <= 0)
		return (printf("Error: Time to die must be > 0\n"), 0);
	if (args->eat_time <= 0)
		return (printf("Error: Time to eat must be > 0\n"), 0);
	if (args->sleep_time <= 0)
		return (printf("Error: Time to sleep must be > 0\n"), 0);
	if (ac == 6 && args->count_eat < 0)
		return (printf("Error: Must eat count must be >= 0\n"), 0);
	return (1);
}

int	parse_program(int ac, char **av, t_program *args)
{
	if (ac < 5 || ac > 6)
		return (printf("Error: Incorrect number of arguments\n"), 0);
	if (!validate_args_numbers(ac, av))
		return (0);
	args->nbr_philo = ft_atoi(av[1], args);
	args->die_time = ft_atoi(av[2], args);
	args->eat_time = ft_atoi(av[3], args);
	args->sleep_time = ft_atoi(av[4], args);
	if (ac == 6)
		args->count_eat = ft_atoi(av[5], args);
	else
		args->count_eat = -1;
	if (!validate_args_values(args, ac))
		return (0);
	return (1);
}
