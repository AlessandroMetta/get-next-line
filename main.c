#include <stdlib.h>
#include <fcntl.h>

int get_next_line(int fd, char **line);

int main (void)
{
    int fd      =   open("text", O_RDONLY, 0);
    int exit    =   0;

    while ((exit = get_next_line(fd, **line)) == 0 || exit == -1)
        ;
    return 0;
}