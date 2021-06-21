#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
#include <string.h>
#include <errno.h>

void    *routine(void *thread_number)
{
    int        i;
    int        cnt;

    i = 0;
    while (i < 5)
    {
        // usleep(1000 * 1000);
        i++;
        printf("thread(%d): %d초 대기\n", *(int *)thread_number, i);
    }
    printf("thread end\n");
    return (thread_number);
}

int        main(void)
{
    pthread_t    thread1;
    pthread_t    thread2;
    int            number1;
    int            number2;
    void        *ret;

    number1 = 1;
    number2 = 2;
    // if (pthread_create(&thread1, NULL, routine, (void *)&number1))
    // {
    //     fprintf(stderr, "thread(1): pthread_create error: %s", strerror(errno));
    //     return (errno);
    // }
    // if (pthread_create(&thread2, NULL, routine, (void *)&number2))
    // {
    //     fprintf(stderr, "thread(2): pthread_create error: %s", strerror(errno));
    //     return (errno);
    // }
    pthread_create(&thread2, NULL, routine, (void *)&number2);
    pthread_create(&thread1, NULL, routine, (void *)&number1);
	printf("왜 여기가 먼저 나와..?\n");
    printf("detach thread2\n");
    pthread_detach(thread2); // main thread에서 join하지 않아도 알아서 진행하고 종료함
    printf("waiting for a thread\n");
    pthread_join(thread1, &ret); // thread1을 대기함, routine의 값을 ret에 넣어줌
    printf("main end: %d\n", *(int *)ret);
    return (0);
}
