#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void random_arr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100 + 1;
}
void quick_sort(int arr[], int left, int right) {
    int p_left = left;
    int p_right = right;
    int pivot = arr[(left + right) / 2];
    int temp;

    while (p_left <= p_right) {
        while (arr[p_left] < pivot) p_left++;
        while (arr[p_right] > pivot) p_right--;
        if (p_left <= p_right) {
            temp = arr[p_left];
            arr[p_left] = arr[p_right];
            arr[p_right] = temp;
            p_left++;
            p_right--;
        }
    }

    if (left < p_right)
        quick_sort(arr, left, p_right);
    if (p_left < right)
        quick_sort(arr, p_left, right);
}

int main() {
    srand(time(NULL));
    int arr[20] = { 0, };
    int n = sizeof(arr) / sizeof(arr[0]);

    random_arr(arr, n);
    quick_sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}