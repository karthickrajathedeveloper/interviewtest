#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define N 10

void *print_thread_id(void *arg) {
    int thread_id = *(int*)arg;
    printf("Thread %d created.\n", thread_id);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[N];
    int thread_ids[N];
    int i;

    for (i = 0; i < N; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, print_thread_id, &thread_ids[i]);
        if (i % 2 == 1) {
            sleep(10);
        }
    }

    for (i = 0; i < N; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
