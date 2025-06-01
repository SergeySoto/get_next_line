/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:37:56 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/05/30 19:10:53 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

int	ft_strlen(char *str , char c)
{
	int	i;

	i = 0;
	while (str[i] != c)
		i++;
	return (i);
}

/*void	*ft_calloc(size_t count, size_t size)
{
	char	*temp;
	size_t	i;

	if (count == 0 || size == 0)
		return (malloc(0));
	i = 0;
	temp = (char *)malloc(count * size);
	if (!temp)
		return (NULL);
	while (i < count)
	{
		temp[i] = '\0';
		i++;
	}
	return (temp);
}*/

/*char	*ft_strdup(const char *s)
{
	int		len;
	char	*result;
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
		i++;
	i++;
	result = (char *)malloc(len * (sizeof(char)));
	if (!result)
		return (NULL);
	i = 0;
	while (result[i] != '\0')
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}*/
/*char	*ft_strchr(const char *s, int c)
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
}*/
/*char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	size_s;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while(s[i] != '\0')
		i++;
	len = i;
	if (len > size_s - start)
		len = size_s - start;
	if (start > size_s)
		return (ft_strdup(""));
	str = (char *)ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	//ft_strlcpy(str, s + start, len + 1);
	i = 0;
	//while()// terminar esto que no se te olvide...mierdas
	return (str);
}*/
char	*ft_strjoin(char *line, char *buf)
{
	int	len_linebuf;
	char	*str;
	int	i;

	len_linebuf = ft_strlen(line,'\0') + ft_strlen(buf,'\0');
	str = malloc((len_linebuf + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	if (line == NULL)
		while (buf[i] != '\0')
		{
			str[i] = buf[i];
			i++;
		}
	i = 0;
	while (buf[i] != '\0')
	{
		str[ft_strlen(line,'\0') + i] = buf[i];
		i++;
	}
	str[ft_strlen(line,'\0') + i] = '\0';
	return (str);
}

/*while (s2[i] != '\0' && i < (ft_strlen(s1,'\0') - 1))
{
	s1[i] = s2[i];
	i++;
}*/