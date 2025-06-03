/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:53:19 by maelmahf          #+#    #+#             */
/*   Updated: 2025/06/03 11:07:30 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void init_engine(t_engine *engine , t_philo *philos , t_mutex *forks)
{
    engine->forks = forks;
    engine->philos = philos;
    
    if(!engine || !philos || !forks)
        error_msg("Error: Engine Initialization Failed\n", EXIT_FAILURE);
    if(pthread_mutex_init(&engine->meal_lock, NULL) != 0 
        || pthread_mutex_init(&engine->write_lock, NULL) != 0)
        destroy_all(engine , "Mutex Initialization Failed\n",-1 , 1);
}

void init_forks(t_engine *engine, t_mutex *forks, int count)
{
    int i;

    i = -1;
    while(++i < count)
    {
        if(pthread_mutex_init(&forks[i], NULL) != 0)
            destroy_all(engine,  "[Mutex Init ERROR]\n", i, 1);
    }
    
}

void    init_philos(t_engine *engine, t_philo *philos, t_mutex *forks, char **av)
{
    int i;

    i = -1;

    while(++i < ft_atoi(av[1]))
    {
        philos[i].id = i + 1;
        philos[i].times.die = ft_atoi(av[2]);
        philos[i].times.eat = ft_atoi(av[3]);
        philos[i].times.sleep = ft_atoi(av[4]);
        philos[i].times.last_meal = get_current_time();
        philos[i].times.born_time = get_current_time();
        philos[i].must_eat = -1;
        if(av[5])
            philos[i].must_eat = ft_atoi(av[5]);
        philos[i].meals_eaten = 0;
        philos[i].philo_count = ft_atoi(av[1]);
        philos[i].mutexes.left_fork = &forks[i];
        if(i == 0)
            philos[i].mutexes.right_fork = &forks[philos[i].philo_count - 1];
        else
            philos[i].mutexes.right_fork = &forks[i - 1];
        philos[i].mutexes.write_lock = &engine->write_lock;
        philos[i].mutexes.meal_lock = &engine->meal_lock;
    }
}