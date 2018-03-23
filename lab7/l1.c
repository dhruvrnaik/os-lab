#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define CAPACITY 5
int item=0, in, out;
int buffer[CAPACITY];
sem_t empty, full, pmutex, cmutex;

void *producer() {
    while(1) {
        sem_wait(&empty);
        item++;
        sem_wait(&pmutex);
        buffer[in] = item;
        printf("Produced: %d\n", buffer[in]);
        in = (in % CAPACITY) + 1;
        sleep(1);
        sem_post(&pmutex);
        sem_post(&full);
    }
}

void *consumer() {
    while(1) {
        sem_wait(&full);
        sem_wait(&cmutex);
        int citem = buffer[out];
        printf("Consumed: %d\n", buffer[out]);
        out = (out % CAPACITY) + 1;
        sleep(1);
        sem_post(&cmutex);
        sem_post(&empty);
    }
}

int main() {
    srand(time(NULL));
    in = out = 1;
    sem_init(&empty, 0, CAPACITY);
    sem_init(&full, 0, 0);
    sem_init(&pmutex, 0, 1);
    sem_init(&cmutex, 0, 1);

    pthread_t prod, cons;
    pthread_create(&prod, NULL, &producer, NULL);
    pthread_create(&cons, NULL, &consumer, NULL);
    pthread_join(prod, NULL);
    pthread_join(cons, NULL);
}