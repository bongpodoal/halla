#include <stdio.h>

int partition(int* arr, int left, int right)
{
    int pivot = arr[left]; // �ǹ��� �迭�� ù ��° ��ҷ� ����
    int i = left + 1;
    int j = right;
    int temp;

    while (i <= j) {
        while (i <= right && arr[i] <= pivot) i++; // �ǹ����� ū ���� ã�Ҵٸ� 
        while (j > left && arr[j] >= pivot) j--; // �ǹ����� ���� ���� ã�Ҵٸ�
        if (i < j) {              // ã�� ������ ��ȯ
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    arr[left] = arr[j]; // ���ʰ� ������ ���� ����
    arr[j] = pivot;

    return i;

}
void quick_sort(int arr[], int left, int right) {
    if (left >= right) return; // ������ ������ ���� ��� ����

    int p = partition(arr, left, right);    // ������ �迭�� ����

    quick_sort(arr, left, right - 1);   // ������ �迭�� ���
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