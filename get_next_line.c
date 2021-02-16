#include "get_next_line.h"

int get_next_line(int fd)
{
    int c;
    while ((c=get_char(fd)) != '\n' && c != EOF)
        write(1, &c, 1);
    if (c == '\n')
    {
        write(1, &c, 1);
        return (1);
    }
    else
        return (0);
}