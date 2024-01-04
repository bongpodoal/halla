#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));
    int num[10];
    int random, j;

    num[0] = rand() % 100 + 1;
    for (int i = 1; i < 10; i++) {
        random = rand() % 100 + 1; // 랜덤값 생성


        int index = 0;
        for (int k = 0; k < i; k++) {        // 만약 난수가 값보다 크면, 그만큼 인덱스를 증가
            if (num[k] <= random) {
                index = k + 1;
            }
        }

        // 찾은 위치로부터 뒤에 있는 모든 요소들을 한 칸씩 뒤로 이동
        for (int j = i; j > index; j--) {
            num[j] = num[j - 1];
        }

        // 난수를 삽입
        num[index] = random;
    }
    for (int i = 0; i < 10; i++) {
        printf("%d ", num[i]); // 값 출력
    }
    return 0;
}