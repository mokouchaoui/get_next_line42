/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokoucha <mokoucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 12:31:41 by mokoucha          #+#    #+#             */
/*   Updated: 2022/04/04 01:15:36 by mokoucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t    ft_strlen(const char *str)
{
    int    i;

    if (!str)
        return (0);
    i = 0;
    while (str[i])
        i++;
    return (i);
}

char    *ft_strjoin_upd(char *s1, char const *s2)
{
    size_t    i;
    size_t    j;
    char    *str;

    if (!s1)
    {
        s1 = (char *)malloc(sizeof(char) * 1);
        s1[0] = '\0';
    }
    if (!s1 || !s2)
        return (NULL);
    str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (!str)
        return (NULL);
    i = -1;
    while (s1[++i])
        str[i] = s1[i];
    j = -1;
    while (s2[++j])
        str[i + j] = s2[j];
    str[i + j] = '\0';
    free(s1);
    return (str);
}

char    *ft_strchr_upd(const char *s, int c)
{
    char    *str;
    int        i;

    if (!s)
        return (NULL);
    str = (char *) s;
    i = ft_strlen(str);
    if (c == '\0')
        return (str + i);
    i = 0;
    while (str[i])
    {
        if (str[i] == (unsigned char) c)
            return (str + i);
        i++;
    }
    return (NULL);
}

char    *ft_copy(char *s1, char *s2)
{
    int    i;

    i = 0;
    while (s2[i])
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
    return (s1);
}

char    *read_from_file(int fd, char *temp)
{
    char    *buf;
    int        sz;

    buf = (char *)malloc(BUFFER_SIZE + 1);
    if (!buf)
        return (NULL);
    sz = 1;
    while (!ft_strchr_upd(temp, '\n') && sz != 0)
    {
        sz = read(fd, buf, BUFFER_SIZE);
        if (sz == -1)
        {
            free(buf);
            return (NULL);
        }
        buf[sz] = '\0';
        temp = ft_strjoin_upd(temp, buf);
    }
    free(buf);
    return (temp);
}
