/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:56:02 by maelmahf          #+#    #+#             */
/*   Updated: 2025/06/02 09:59:51 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void    *observer(void *ptr)
{
    t_philo *philos;
    int i;

    philos = (t_philo *)ptr;
    while(1)
    {
        i = -1;
        while(++i < philos[0].philo_count)
        {
            pthread_mutex_lock(philos->mutexes.meal_lock);
            if(get_current_time() - philos[i].times.last_meal > philos[i].times.die)
            {
                pthread_mutex_unlock(philos->mutexes.meal_lock);
                print_action(&philos[i], RED" died"RESET);
                pthread_mutex_lock(philos->mutexes.write_lock);
                return (NULL);
            }
            pthread_mutex_unlock(philos->mutexes.meal_lock);
        }
        if (is_all_eat(philos))
            return (NULL); 
    }
    return (NULL);
}

void    launcher(t_engine *engine, int count)
{
    t_id  observer_id;
    // int i;

    // i = -1;
    if(pthread_create(&observer_id , NULL, &observer , engine->philos)  != 0)
        destroy_all(engine, "[Thread Creation ERROR]\n", count, 1);
    // while(++i < count)
    // {
        
    // }
}
