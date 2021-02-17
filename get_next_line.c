#include "get_next_line.h"

int ft_read_line(char **p_el, char **rescue, int fd, int size)
{

}

int ft_return_value(char **p_el , char **rescue)
{

}

int get_next_line(int fd, char **line)
{
    static char		*rescue[256];
	char			*p_el;

    p_el = NULL;
	if (fd < 0 || fd > 256 || BUFFER_SIZE <= 0 || !line)
		return (-1);
    if (!rescue[fd])
	{
		if (!(rescue[fd] = ft_strdup("")))
			return (-1);
	}
    if ((ft_read_line(&p_el, &rescue[fd], fd, BUFFER_SIZE)) < 0)
	{
		free(rescue[fd]);
		return (-1);
	}
    if (p_el)
        *p_el = '\0';
    if (!(*line = ft_strdup(rescue[fd])))
	{
		free(rescue[fd]);
		return (-1);
	}
	return (ft_return_value(&p_el, &rescue[fd]));
}