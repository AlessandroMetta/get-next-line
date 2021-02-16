#include "get_next_line.h"

int get_char(int fd)
{
    char c;

    return ( (read(fd, &c, 1) == 1) ? ((unsigned char)c) : (EOF) );
}