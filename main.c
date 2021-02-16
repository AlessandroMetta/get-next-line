#include "get_next_line.h"

int main()
{
    int fd;

    fd = open("ciao.txt", O_RDONLY, 0);
    int c;
    while (get_next_line(fd) != 0)
        ;
    close(fd);
    return 0;
}