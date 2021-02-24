/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 16:28:54 by ametta            #+#    #+#             */
/*   Updated: 2021/02/24 16:28:57 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_reading(char **end_line, char **buffer, int fd, int b_size)
{
	char	*buf;
	int		ret;
	char	*temp;

	ret = b_size;
	while (!(*end_line = ft_strchr(*buffer, '\n')) && ret == b_size)
	{
		if (!(buf = (char *)malloc(sizeof(char) * (b_size + 1))))
			return (-1);
		if ((ret = read(fd, buf, b_size)) < 0)
		{
			free(buf);
			return (-1);
		}
		buf[ret] = '\0';
		if (!(temp = ft_strjoin(*buffer, buf)))
		{
			free(buf);
			return (-1);
		}
		free(buf);
		free(*buffer);
		*buffer = temp;
	}
	return (ret);
}

int		ft_result(char **end_line, char **buffer)
{
	char	*temp;

	if (*end_line)
	{
		if (!(temp = ft_strdup(*end_line + 1)))
		{
			free(*buffer);
			return (-1);
		}
		free(*buffer);
		*buffer = temp;
		return (1);
	}
	free(*buffer);
	*buffer = NULL;
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char		*buffer[256];
	char			*end_line;

	if (fd < 0 || fd > 256 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	end_line = NULL;
	if (!buffer[fd])
	{
		if (!(buffer[fd] = ft_strdup("")))
			return (-1);
	}
	if ((ft_reading(&end_line, &buffer[fd], fd, BUFFER_SIZE)) < 0)
	{
		free(buffer[fd]);
		return (-1);
	}
	if (end_line)
		*end_line = '\0';
	if (!(*line = ft_strdup(buffer[fd])))
	{
		free(buffer[fd]);
		return (-1);
	}
	return (ft_result(&end_line, &buffer[fd]));
}
