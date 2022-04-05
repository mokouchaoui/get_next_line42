/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokoucha <mokoucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 00:08:11 by mokoucha          #+#    #+#             */
/*   Updated: 2022/04/04 00:51:24 by mokoucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
char    *ft_copy(char *s1, char *s2);
char    *read_from_file(int fd, char *temp);
char    *ft_strchr_upd(const char *s, int c);
char    *ft_strjoin_upd(char *s1, char const *s2);
size_t    ft_strlen(const char *str);
char *get_next_line(int fd);

#endif
