/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokoucha <mokoucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 05:42:32 by mokoucha          #+#    #+#             */
/*   Updated: 2022/04/05 05:42:39 by mokoucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*final_line(int nl_position, char **buffer)
{
	char	*res;
	char	*tmp;

	if (nl_position <= 0)
	{
		if (**buffer == 0)
		{
			free(*buffer);
			*buffer = NULL;
			return (NULL);
		}
		res = *buffer;
		*buffer = NULL;
		return (res);
	}
	tmp = ft_substr(*buffer, nl_position, BUFFER_SIZE);
	res = *buffer;
	res[nl_position] = 0;
	*buffer = tmp;
	return (res);
}

char	*read_text(int fd, char **buffer, char *str)
{
	char	*new_line;
	char	*tmp;
	int		a;

	a = 0;
	tmp = NULL;
	new_line = ft_strchr(*buffer, '\n');
	while (!new_line)
	{
		a = read(fd, str, BUFFER_SIZE);
		if (a <= 0)
			return (final_line(a, buffer));
		str[a] = 0;
		tmp = ft_strjoin(*buffer, str);
		free(*buffer);
		*buffer = tmp;
		new_line = ft_strchr(*buffer, '\n');
	}
	return (final_line(new_line - *buffer + 1, buffer));
}

char	*get_next_line(int fd)
{
	static char	*buffer[257];
	char		*str;
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 257)
		return (NULL);
	str = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!str)
		return (NULL);
	if (!buffer[fd])
		buffer[fd] = ft_strdup("");
	res = read_text(fd, &buffer[fd], str);
	free(str);
	return (res);
}
