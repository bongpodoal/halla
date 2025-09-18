#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rand_arr(int arr[], int N) {
    for (int i = 0; i < N; i++) {
        int num;
        int flag;

        while (1) {
            num = rand() % N;  
            flag = 0;

            for (int j = 0; j < i; j++) {
                if (arr[j] == num) {
                    flag = 1;
                    break;
                }
            }

            if (!flag) {  
                arr[i] = num;
                break;
            }
        }
    }
}

int main() {
    int N = 9;
    int arr[9];

    srand(time(NULL));  
    rand_arr(arr, N);

    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
