/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 20:01:22 by yfang             #+#    #+#             */
/*   Updated: 2024/02/20 16:33:23 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*save_and_clear(char *str)
{
	char	*new_line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	new_line = ft_calloc(ft_strlen2(str, 0) - i + 1, sizeof(char));
	i++;
	while (str[i] != '\0')
		new_line[j++] = str[i++];
	free(str);
	if (new_line[0] == '\0')
	{
		free(new_line);
		return (NULL);
	}
	return (new_line);
}

char	*ft_get_line(char *str)
{
	char	*line;
	ssize_t	i;
	ssize_t	len;

	i = 0;
	if (str[i] == '\0')
		return (NULL);
	len = ft_strlen2(str, '\n') + 1;
	if (!len)
		return (NULL);
	line = ft_calloc2(len, sizeof(char));
	while (str[i] != '\n' && str[i] != '\0')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n' && str[i] != '\0')
		line[i++] = '\n';
	return (line);
}

char	*join_and_free(char *str, char *tmp)
{
	char	*concat_str;

	concat_str = ft_strjoin2(str, tmp);
	free(str);
	return (concat_str);
}

char	*find_line(int fd, char *str)
{
	char	*tmp;
	ssize_t	br;

	if (!str)
		str = ft_calloc2(1, sizeof(char));
	tmp = ft_calloc2(BUFFER_SIZE + 1, sizeof(char));
	br = 1;
	while (br > 0)
	{
		br = read(fd, tmp, BUFFER_SIZE);
		if (br < 0)
		{
			free(tmp);
			return (NULL);
		}
		tmp[br] = '\0';
		str = join_and_free(str, tmp);
		if (ft_strchr2(str, '\n') == 1)
			break ;
	}
	free(tmp);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[1024];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= 1024)
		return (NULL);
	if (read(fd, 0, 0) == -1)
	{
		if (str[fd] != NULL)
		{
			free(str[fd]);
			str[fd] = NULL;
			return (NULL);
		}
		return (NULL);
	}
	str[fd] = find_line(fd, str[fd]);
	line = ft_get_line(str[fd]);
	str[fd] = save_and_clear(str[fd]);
	return (line);
}
