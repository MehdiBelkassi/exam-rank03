/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelkass <mbelkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 22:26:20 by mbelkass          #+#    #+#             */
/*   Updated: 2025/06/29 21:00:45 by mbelkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char *ft_strdup(char *str)
{
    int i = 0;
    char *copy;

    copy = malloc(sizeof(char) * strlen(str) + 1);
    if (!copy)
        return (NULL);
    
    while(str[i])
    {
        copy[i] = str[i];
        i++;
    }
    copy[i] = 0;
    return(copy);
}

char    *get_next_line(int fd)
{
    static int b_pos;
    static int b_read;
    static char buffer[BUFFER_SIZE];
    char line[70000];
    int i = 0;
    
    if (BUFFER_SIZE < 1 || fd < 0)
        return NULL;

    while(1337)
    {
        if (b_pos >= b_read)
        {
            b_read = read(fd,buffer,BUFFER_SIZE);
            b_pos = 0;
            if (b_read < 1)
                break;
        }
        line[i++] = buffer[b_pos++];
        if (buffer[b_pos - 1] == '\n')
            break;
    }
    if (i == 0)
        return NULL;
    line[i] = 0;
    return (ft_strdup(line));
}
