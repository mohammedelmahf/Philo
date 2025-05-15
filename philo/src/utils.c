/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:02:27 by maelmahf          #+#    #+#             */
/*   Updated: 2025/05/15 12:33:47 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

// int error_msg(char *msg ,t_params *args,t_philo *p ,  int malloc)
// {
//     if(malloc)
//     {
//         if(args->death)
//             free(args->death);
//         if(args->fork)
//             free(args->fork);
//         if(p)
//             free(p);
//     }
//     return(printf("%s" , msg));
// }

void error_msg(char *text, int signal)
{
    if(text)
        write(2,text , ft_strlen(text) + 1);
    exit(signal);
}