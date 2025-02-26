#include<pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
int g=0;
void *thread_function(void *arg) {
    sleep(2);
    int *a = arg;
    static int s = 0;
    int process_id = getpid();
    // pid_t tid = syscall(SYS _gettid);
    // a=malloc(sizeof(int));
    *a=20;

    // pthread_getunique_np(&self, &tid);
    printf("Thread function called thread_id: %d, g: %d, s: %d, process_id: %d, a(passed val): %d \n", pthread_self(), g++, s++, process_id, a ? *a : 0);
    return NULL;
}

int main() {
    pthread_t thread;
    pthread_t thread2;
    printf("before thread\n");
    // for(int i=0;i<100;i++)
    //     pthread_create(&thread, NULL, thread_function, NULL);
    int *a= malloc(sizeof(int));
    *a=10;
    pthread_create(&thread2, NULL, thread_function, a);

    // pthread_exit(NULL);
    pthread_join(thread2, NULL); // to wait for the thread to complete (dont stop main thread before it completes)
    printf("after thread %d",*a);
    exit(0);
}