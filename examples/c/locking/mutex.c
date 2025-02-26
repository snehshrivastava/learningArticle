#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <unistd.h>
int g = 0;

pthread_t tid[2];

// since data is passed down as a pointer if we wanna return the data back we need to update the passed pointer

pthread_mutex_t mutex;
void *thread_function(void *arg)
{
    pthread_mutex_lock(&mutex);
    int process_id = getpid();
    //  thread_id = pthread_self();
    unsigned long i = 0;
    g += 1;
    printf("\n Job %d has started thread id: %d\n", g, pthread_self());

    sleep(2);

    printf("\n Job %d has finished\n", g);

    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main(void)
{
    int i = 0;
    int error;

    if (pthread_mutex_init(&mutex, NULL) != 0)
    {
        printf("\n mutex init has failed\n");
        return 1;
    }

    while (i < 4)
    {
        error = pthread_create(&(tid[i%2]),
                               NULL,
                               &thread_function, NULL);
        if (error != 0)
            printf("\nThread can't be created :[%d]",
                   error);
        i++;
    }

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_mutex_destroy(&mutex);

    return 0;
}