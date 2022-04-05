/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokoucha <mokoucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 12:44:01 by mokoucha          #+#    #+#             */
/*   Updated: 2022/04/03 22:45:39 by mokoucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *upto_first_nl_or_0(char *str)
{
    char    *short_str;
    int        i;

    i = 0;
    if (!str[i])
        return (NULL);
    while (str[i] && str[i] != '\n')
        i++;
    short_str = (char *)malloc(sizeof(char) *(i + 2));
    if (!short_str)
        return (NULL);
    i = 0;
    while (str[i] && str[i] != '\n')
    {
        short_str[i] = str[i];
        i++;
    }
    if (str[i] == '\n')
    {
        short_str[i] = '\n';
        i++;
    }
    short_str[i] = '\0';
    return (short_str);
}

char    *after_nl(char *str)
{
    char    *short_str;
    int        i;

    i = 0;
    while (str[i] && str[i] != '\n')
        i++;
    if (!str[i])
    {
        free(str);
        return (NULL);
    }
    short_str = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
    if (!short_str)
        return (NULL);
    short_str = ft_copy(short_str, str + i + 1);
    free(str);
    return (short_str);
}

char    *get_next_line(int fd)
{
    static char    *temp;
    char        *line;

    if (fd < 0 || fd > 65535 || BUFFER_SIZE <= 0)
        return (NULL);
    temp = read_from_file(fd, temp);
    if (!temp)
        return (NULL);
    line = upto_first_nl_or_0(temp);
    temp = after_nl(temp);
    return (line);
}
