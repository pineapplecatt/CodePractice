#include <unistd.h>
#include <iostream>
#include "mutexLock.hpp"

#define NUM_THREADS 10000

int num = 0;
Mutex mutex;

void* count(void* args) {
    MutexLock lock(&mutex);
    num++;
}

int main() {
    int t;
    pthread_t thread[NUM_THREADS];

    for (t = 0; t < NUM_THREADS; t++) {
        int ret = pthread_create(&thread[t], NULL, count, NULL);
        if (ret) {
            return -1;
        }
    }

    for (t = 0; t < NUM_THREADS; t++)
        pthread_join(thread[t], NULL);
    std::cout << num << std::endl;
    return 0;
}