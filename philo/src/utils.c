/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:02:27 by maelmahf          #+#    #+#             */
/*   Updated: 2025/04/04 17:06:09 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int error_msg(char *msg ,t_params *args,t_philo *p ,  int malloc)
{
    if(malloc)
    {
        if(args->death)
            free(args->death);
        if(args->fork)
            free(args->fork);
        if(p)
            free(p);
    }
    return(printf("%s" , msg));
}