/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwong <hwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:04:58 by hwong             #+#    #+#             */
/*   Updated: 2023/02/19 19:23:16 by hwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_join(char *buff, char *buffer)
{
	char	*dest;

	dest = ft_strjoin(buff, buffer);
	free(buff);
	return (dest);
}

static char	*free_used(char *buff)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	line = malloc((ft_strlen(buff) - i + 1) * sizeof(char));
	i = i + 1;
	j = 0;
	while (buff[i])
		line[j++] = buff[i++];
	line[j] = '\0';
	free(buff);
	return (line);
}

static char	*get_line(char *buff)
{
	char	*line;
	int		i;

	i = 0;
	if (!buff[i])
		return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	line = malloc((i + 2) * sizeof(char));
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		line[i] = buff[i];
		i++;
	}
	if (buff[i] && buff[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*read_file(int fd, char *buff)
{
	char	*buffer;
	int		s;

	if (!buff)
	{
		buff = malloc(1);
		*buff = '\0';
	}
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	s = 1;
	while (s > 0)
	{
		s = read(fd, buffer, BUFFER_SIZE);
		if (s == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[s] = 0;
		buff = ft_join(buff, buffer);
		if (check_c(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*buff[1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buff[fd] = read_file(fd, buff[fd]);
	if (!buff[fd])
		return (NULL);
	line = get_line(buff[fd]);
	buff[fd] = free_used(buff[fd]);
	return (line);
}
