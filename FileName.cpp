#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));
    int num[10];
    int random, j;

    num[0] = rand() % 100 + 1;
    for (int i = 1; i < 10; i++) {
        random = rand() % 100 + 1; // ������ ����


        int index = 0;
        for (int k = 0; k < i; k++) {        // ���� ������ ������ ũ��, �׸�ŭ �ε����� ����
            if (num[k] <= random) {
                index = k + 1;
            }
        }

        // ã�� ��ġ�κ��� �ڿ� �ִ� ��� ��ҵ��� �� ĭ�� �ڷ� �̵�
        for (int j = i; j > index; j--) {
            num[j] = num[j - 1];
        }

        // ������ ����
        num[index] = random;
    }
    for (int i = 0; i < 10; i++) {
        printf("%d ", num[i]); // �� ���
    }
    return 0;
}