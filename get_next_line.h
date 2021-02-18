/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:54:16 by ametta            #+#    #+#             */
/*   Updated: 2021/02/18 16:01:51 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

int             ft_read_line(char **p_el, char **rescue, int fd, int buff_size);
int             ft_return(char **p_el, char **rescue);
int             get_next_line(int fd, char **line);
char        *strchr(const char *s, int c);
char        *ft_strdup(const char *s1);

#endif