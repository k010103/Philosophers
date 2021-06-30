
#include <stdio.h>
#include <sys/time.h>

// 철학자가 죽었는지 확인하는방법.
// (현재시간 - 철학자의 마지막 식사시간)
int        main(void)
{
    struct timeval    my_time;
    gettimeofday(&my_time, NULL);
    printf("time : %ld\n", my_time.tv_sec);
    printf("macro time : %d\n", my_time.tv_usec);
    return (0);
}
