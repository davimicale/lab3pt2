#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int NUM_THREADS; // Declare NUM_THREADS
int ITERATIONS;  // Declare ITERATIONS

double pi = 0.0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *calculate_pi(void *thread_id) {
    int id = *(int *)thread_id;
    double sum = 0.0;
    int start = id * ITERATIONS / NUM_THREADS;
    int end = (id + 1) * ITERATIONS / NUM_THREADS;

    for (int i = start; i < end; i++) {
        double x = (double)i / ITERATIONS;
        sum += 4.0 / (1.0 + x * x);
        printf("iteração: %f\n", sum);
    }

    pthread_mutex_lock(&mutex);
    pi += sum;
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int main() {
    printf("Digite o número de threads: ");
    scanf("%d", &NUM_THREADS);

    printf("Digite o número de iterações: ");
    scanf("%d", &ITERATIONS);

    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, calculate_pi, (void *)&thread_ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pi /= ITERATIONS;
    printf("Pi calculado usando %d threads e %d iterações: %f\n", NUM_THREADS, ITERATIONS, pi);

    return 0;
}
