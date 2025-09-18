#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rand_arr(int arr[], int N) {
    for (int i = 0; i < N; i++) {
        arr[i] = i;
    }

    for (int i = N - 1; i > 0; i--) {
        int j = rand() % N;
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}

int main() {
    int arr[9];
    int N = sizeof(arr) / sizeof(int);

    srand(time(NULL)); 
    rand_arr(arr, N);

    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
