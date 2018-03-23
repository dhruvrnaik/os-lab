#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFLEN 10

int readerCount;
sem_t mutex, write_s;
char buffer[BUFLEN+1];

void *reader() {
    while(1) {
        sem_wait(&mutex);
        readerCount++;
        if(readerCount == 1) {
            sem_wait(&write_s);
        }
        sem_post(&mutex);
        write(1, buffer, strlen(buffer));
        sleep(1);
        sem_wait(&mutex);
        readerCount--;
        if(readerCount == 0) {
            sem_post(&write_s);
        }
        sem_post(&mutex);
    }
}

void *writer() {
    while(1) {
        sem_wait(&write_s);
        strncpy(buffer,"Reading\n", BUFLEN);
        buffer[BUFLEN] = '\0';
        printf("Writing\n");
        sleep(1);
        sem_post(&write_s);
    }
}

int main() {
    int readerCount = 0;
    sem_init(&mutex, 0, 1);
    sem_init(&write_s, 0, 1);
    sem_post(&mutex);
    sem_post(&write_s);

    pthread_t readers[5];
    pthread_t writers[3];

    int i;
    for(i = 0; i < 5; i++) {
        pthread_create(&readers[i], NULL, &reader, NULL);
    }

    for(i = 0; i < 3; i++) {
        pthread_create(&writers[i], NULL, &writer, NULL);
    }

    for(i = 0; i < 5; i++) {
        pthread_join(readers[i], NULL);
    }

    for(i = 0; i < 3; i++) {
        pthread_join(writers[i], NULL);
    }    
}