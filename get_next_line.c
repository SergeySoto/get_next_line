/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:35:52 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/05/30 19:39:09 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	else
		return (NULL);
}

char	*fill_line(int fd, char *line)
{
	int	ch_read;
	char	*buf;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	//buf[BUFFER_SIZE + 1] = '\0';
	
	while((ch_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		//ch_read = read(fd, buf, BUFFER_SIZE);
		buf[ch_read] = '\0';
		line = ft_strjoin(line, buf);
	}
	free(buf);
	return (line);
}

// char	*get_next_line(int fd)
// {
// 	static char	*list;
// 	char	*new_line;
// 	int	i;

// 	i = 0;
// 	list = NULL;
// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	while ( )
// 		new_line = fill_line(fd, list);

// }

int	main(void)
{
int	fd;
static char	*line;

line = NULL;

fd = open("file.txt", O_RDONLY);
line = fill_line(fd, line);
printf("%s", line);
// while ((line = get_next_line(fd)))
// {
// 	printf("buf -> %s\n", line);
// 	free(line);
// }
close(fd);
return (0);
}

/*int	main(void)
{
char	*str1 = "Ser";
char	*str2 = "gey";
char	*result;

result = ft_strjoin(str1, str2);
printf("%s\n", result);
return (0);
}*/
