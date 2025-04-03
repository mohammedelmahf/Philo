/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 18:58:40 by maelmahf          #+#    #+#             */
/*   Updated: 2025/04/03 19:10:43 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int     init_args(t_params *p, char **av)

int main(int ac , char **av)
{
    t_params args;

    if((ac != 5 && ac != 6) || init_args(&p , av))
        return(error_message("Error : invalid argument"))
}