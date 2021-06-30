#include <stdio.h>
#include <unistd.h>

int        main(void)
{
    int i = 0;
    while (i < 3)
    {
        usleep(1000 * 1000);
        i++;
        printf("%d초 째 대기 중\n", i);
    }
    return (0);
}
