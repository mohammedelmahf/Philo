/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 20:32:08 by maelmahf          #+#    #+#             */
/*   Updated: 2025/03/25 21:00:25 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 32
#endif

char *ft_strdup(char *str)
{
    int i = 0;
    char *ptr;

    while(str[i])
        i++;
    ptr = malloc((i + 1) * sizeof(char));
    
    i = 0;
    if(!ptr)
        return NULL;
    while(str[i])
    {
        ptr[i] = str[i];
        i++;
    }
    ptr[i] = '\0';
    return ptr;
}

char *get_next_line(int fd)
{
    static char buffer_read[BUFFER_SIZE];
    static int copy ;
    static int buffer_readed;
    static char line[7000];
    int i = 0;
    
    if(fd < 0 || BUFFER_SIZE < 0 )
        return NULL;
    while(1)
    {
        if(copy >= buffer_readed)
        {
            buffer_readed = read(fd , buffer_read , BUFFER_SIZE);
            copy = 0;
            if(buffer_readed <= 0)
                break;
        }
        line[i++] = buffer_read[copy++];
        if(line[i - 1] == '\n')
            break;
    }
    line[i] = '\0';
    if(i == 0)
        return NULL;
    return(ft_strdup(line));
}

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *line;

    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return 0;
}