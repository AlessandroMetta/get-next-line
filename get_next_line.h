#ifndef LIBFT_H
# define LIBFT_H

#include <stdio.h>
#include <unistd.h>
#include  <fcntl.h>

int get_next_line(int fd, char **line);
int ft_read_line(char **p_el, char **rescue, int fd, int size);
int ft_return_value(char **p_el , char **rescue);

#endif