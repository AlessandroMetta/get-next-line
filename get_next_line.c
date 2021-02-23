/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 10:47:46 by ametta            #+#    #+#             */
/*   Updated: 2021/02/19 12:50:09 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_readline(char **bef_read, int fd, char **p_endl, int buff_size)
{
	char	*new_read;
	char	*temp;
	int		ret_val;

	ret_val = buff_size;
	while (!(p_endl = ft_strchr(*bef_read, '\n')) && ret_val == buff_size)
	{
		if (!(new_read = (char *)malloc(sizeof(char) * buff_size + 1)))
			return (-1);
		if ((ret_val = read(fd, new_read, buff_size)) < 0)
		{
			free(new_read);
			return (-1);
		}
		new_read[ret_val] = '\0';
		if (!(temp = ft_strjoin(*bef_read, new_read)))
		{
			free(new_read);
			return (-1);
		}
		free(*bef_read);
		free(new_read);
		*bef_read = temp;
	}
	return (ret_val);
}

int	ft_return(char **p_endl, char **final_read)
{
	char	*temp;

	if (*p_endl)
	{
		if (!(temp = ft_strdup(p_endl + 1)))
		{
			free(*final_read);
			return (-1);
		}
		free(*final_read);
		*final_read = temp;
		return (1);
	}
	free(*final_read);
	*final_read = NULL;
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char	*rescue[256];
	char	*p_endl;

	if (fd < 0 || fd > 255 || !line || BUFF_SIZE <= 0)
		return (-1);
	p_endl = NULL;
	if (!(rescue[fd]))
	{
		if (!(rescue[fd] = ft_strdup("")))
			return (-1);
	}
	if ((ft_readline(&rescue[fd], fd, &p_endl, BUFF_SIZE)) < 0)
	{
		free(rescue[fd]);
		return (-1);
	}
	if (p_endl)
		p_endl = '\0';
	if (!(line = ft_strdup(rescue[fd])))
	{
		free(rescue[fd]);
		return (-1);
	}
	return (ft_return(&p_endl, &rescue[fd]));
}
