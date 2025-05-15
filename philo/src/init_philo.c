/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:53:19 by maelmahf          #+#    #+#             */
/*   Updated: 2025/05/15 13:03:56 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"


void check_engine(t_engine *engine , t_philo *philos , t_mutex *forks)
{
    engine->forks = forks;
    engine->philos = philos;
    
    if(!engine || !philos || !forks)
        error_msg("Error: Engine Initialization Failed\n", EXIT_FAILURE);
    if(pthread_mutex_init(&engine->meal_lock, NULL) != 0 
        || pthread_mutex_init(&engine->write_lock, NULL) != 0)
        destroy_all(engine , "Mutex Initialization Failed\n",-1 , 1);
}
