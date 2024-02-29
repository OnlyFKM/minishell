/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:12:12 by frcastil          #+#    #+#             */
/*   Updated: 2023/08/25 16:00:39 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_nextline(char *buffer)
{
	int		i;
	int		j;
	char	*nextline;

	i = 0;
	while (buffer[i] != 0 && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free(buffer), buffer = NULL, NULL);
	nextline = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	if (!nextline)
		return (free(buffer), buffer = NULL, NULL);
	j = 0;
	while (buffer[++i] != 0)
		nextline[j++] = buffer[i];
	nextline[j] = '\0';
	return (free(buffer), buffer = NULL, nextline);
}

static char	*ft_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] != 0 && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 1 + (buffer[i] == '\n'), sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] != 0 && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*ft_read_line(int fd, char *buffer)
{
	char	*str;
	ssize_t	readed;

	str = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!str)
		return (free(buffer), buffer = NULL, NULL);
	readed = 1;
	while (readed != 0 && !ft_strchr(buffer, '\n'))
	{
		readed = read(fd, str, BUFFER_SIZE);
		if (readed < 0)
			return (free(str), free(buffer), buffer = NULL, NULL);
		str[readed] = '\0';
		buffer = ft_strjoin(buffer, str);
		if (!buffer)
			return (free(buffer), buffer = NULL, free(str), NULL);
	}
	return (free(str), buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) < 0)
	{
		if (buffer != NULL)
		{
			free(buffer);
			buffer = NULL;
		}
		return (NULL);
	}
	buffer = ft_read_line(fd, buffer);
	if (!buffer)
		return (free(buffer), buffer = NULL, NULL);
	line = ft_line(buffer);
	if (!line)
		return (free(buffer), buffer = NULL, NULL);
	buffer = ft_nextline(buffer);
	if (!buffer)
		return (free(buffer), buffer = NULL, line);
	return (line);
}

/* int main(void)
{
	int	fd;
	char *line;

	fd = open("test.txt", 0);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		line = get_next_line(fd);
	}
	close(fd);
} */