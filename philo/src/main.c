/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 18:58:40 by maelmahf          #+#    #+#             */
/*   Updated: 2025/04/04 17:06:32 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int     init_args(t_params *p, char **av)
{
    int mutex;

    mutex = -1;
    
    p->num = ft_atoi(av[1]);
    p->t2d = ft_atoi(av[2]);
    p->t2e = ft_atoi(av[3]);
    p->t2s = ft_atoi(av[4]);
    p->max_iter = -2;
    p->check_meal = 0;
    p->start = 0;
    p->ready = 0;
    if(av[5])
    {
        p->check_meal = 1;
        p->max_iter = ft_atoi(av[5]);
    }
    p->over = 0;
    if(p->num > 0)
        mutex = init_args_mutex(p);
        
    
    
    
}

int main(int ac , char **av)
{
    t_params args;

    if((ac != 5 && ac != 6) || init_args(&args , av))
        return(error_message("Error : invalid argument"));
}