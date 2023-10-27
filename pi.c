#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

long long n;              // Número de termos na série
int thread_count;         // Número de threads
double sum = 0.0;         // Variável para armazenar a soma

void* Thread_sum(void* rank) {
    long my_rank = (long)rank;
    double factor;
    long long i;
    long long my_n = n / thread_count;
    long long my_first_i = my_n * my_rank;
    long long my_last_i = my_first_i + my_n;

    if (my_first_i % 2 == 0) /* my_first_i is even */
        factor = 1.0;
    else /* my_first_i is odd */
        factor = -1.0;

    for (i = my_first_i; i < my_last_i; i++, factor = -factor) {
        sum += factor / (2 * i + 1);
        printf("iteração: %f\n", sum);
    }

    return NULL;
}

int main() {
    long i;
    pthread_t* thread_handles;

    printf("Número de termos na série: ");
    scanf("%lld", &n);
    printf("Número de threads: ");
    scanf("%d", &thread_count);

    thread_handles = (pthread_t*)malloc(thread_count * sizeof(pthread_t));

    for (i = 0; i < thread_count; i++) {
        pthread_create(&thread_handles[i], NULL, Thread_sum, (void*)i);
    }

    for (i = 0; i < thread_count; i++) {
        pthread_join(thread_handles[i], NULL);
    }

    sum *= 4;  // Multiplica por 4 para obter uma estimativa de pi
    printf("Estimativa de pi: %f\n", sum);

    free(thread_handles);

    return 0;
}
