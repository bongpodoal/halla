#include <stdio.h>
#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = 0;
int rear = -1;

int is_full() {
    return rear >= MAX_SIZE - 1;
}

int is_empty() {
    return front > rear;
}

void enqueue(int value) {
    if (is_full()) {
        printf("큐가 가득 차서 값을 넣지 못했습니다.\n");
        return;
    }
    queue[++rear] = value;
}

int dequeue() {
    if (is_empty()) {
        printf("큐가 비어있어서 값을 빼지 못했습니다.\n");
        return -1;
    }
    return queue[front++];
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("뺀 값 %d\n", dequeue());
    printf("뺀 값 %d", dequeue());

    return 0;
}