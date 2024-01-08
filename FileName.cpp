#include <stdio.h>

int partition(int* arr, int left, int right)
{
    int pivot = arr[left]; // 피벗을 배열의 첫 번째 요소로 설정
    int i = left + 1;
    int j = right;
    int temp;

    while (i <= j) {
        while (i <= right && arr[i] <= pivot) i++; // 피벗보다 큰 값을 찾았다면 
        while (j > left && arr[j] >= pivot) j--; // 피벗보다 작은 값을 찾았다면
        if (i < j) {              // 찾은 값들을 교환
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    arr[left] = arr[j]; // 왼쪽과 오른쪽 순서 변경
    arr[j] = pivot;

    return i;

}
void quick_sort(int arr[], int left, int right) {
    if (left >= right) return; // 분할할 구간이 없는 경우 종료

    int p = partition(arr, left, right);    // 분할한 배열을 정렬

    quick_sort(arr, left, right - 1);   // 분할한 배열을 재귀
    quick_sort(arr, left + 1, right);
}

int main() {
    int arr[] = { 10, 30, 22, 50, 20, 90, 83, 2, 6, 66 };

    quick_sort(arr, 0, 9);

    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}