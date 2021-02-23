/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 11:42:55 by ametta            #+#    #+#             */
/*   Updated: 2021/02/19 12:54:50 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

int				get_next_line(int fd, char **line);
int				ft_return(char **p_endl, char **final_read);
int				ft_readline(char **bef_read, int fd, char **p_endl,
							int buff_size);
char			ft_strchr(const char *s, int c);
char			*ft_strdup(const char *str);
char			*ft_strjoin(const char *str1, const char *str2);

#endif
