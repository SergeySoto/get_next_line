/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:35:52 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/06/18 12:09:47 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get__line(int fd, char *line)
{
	int		ch_read;
	char	*buf;

	if (!line)
		line = ft_strdup("");
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf || !line)
		return (NULL);
	ch_read = 1;
	while (ch_read > 0 && ft_strchr(line, '\n') == NULL)
	{
		ch_read = read(fd, buf, BUFFER_SIZE);
		if (ch_read < 0)
		{
			free(buf);
			free(line);
			line = NULL;
			return (NULL);
		}
		buf[ch_read] = '\0';
		line = ft_strjoin(line, buf);
	}
	free(buf);
	return (line);
}

char	*cut__line(char *line)
{
	int		i;
	char	*aux;

	i = 0;
	if (!line || !line[0])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	aux = ft_substr(line, 0, i);
	if (!aux)
	{
		free(aux);
		return (NULL);
	}
	return (aux);
}

char	*update_static(char *line)
{
	char	*rest;
	int		i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\n')
		i++;
	rest = ft_substr(line, i, ft_strlen(line + i, '\0'));
	free(line);
	if (!rest)
	{
		free(rest);
		return (NULL);
	}
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*line[MAX_FD];
	char		*new_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(line[fd]);
		return (NULL);
	}
	line[fd] = get__line(fd, line[fd]);
	if (!line[fd] || line[fd][0] == '\0')
	{
		free(line[fd]);
		line[fd] = NULL;
		return (NULL);
	}
	new_line = cut__line(line[fd]);
	if (!new_line)
	{
		free(line[fd]);
		line[fd] = NULL;
		return (NULL);
	}
	line[fd] = update_static(line[fd]);
	return (new_line);
}
