#include <stdio.h>

// 큐 최대 크기 정의.
#define QUEUE_SIZE 10

// 큐 구조체 정의.
typedef struct {
    int data[QUEUE_SIZE];
    int front;
    int rear;
} Queue;

// 큐 초기화 함수.
void InitQueue(Queue* p_queue) {
    p_queue->front = 0;   // 초기 front는 0.
    p_queue->rear = -1;   // 초기 rear는 -1.
}

// 큐를 앞으로 댕기는 함수.
void BringForward(Queue* p_queue) {
    if (p_queue->front == 0) { // 앞 공간이 없으면 그대로 둔다.
        return;
    }

    int count = p_queue->rear - p_queue->front + 1; // 남은 데이터 개수.
    for (int i = 0; i < count; i++) {
        p_queue->data[i] = p_queue->data[p_queue->front + i]; // 데이터를 앞으로 이동.
    }

    p_queue->front = 0;        // front를 0으로 리셋.
    p_queue->rear = count - 1; // rear를 마지막 인덱스로 조정.
}

// 큐에 데이터 삽입 함수.
void Enqueue(Queue* p_queue, int value) {
    if (p_queue->rear >= QUEUE_SIZE - 1) { // 오버플로우 체크.
        printf("Warn! Overflow!\n");
        return;
    }

    p_queue->data[++(p_queue->rear)] = value; // rear 증가 후 데이터 삽입.
}

// 큐에서 데이터 꺼내기 함수.
int Dequeue(Queue* p_queue) {
    if (p_queue->rear < p_queue->front) { // 언더플로우 체크.
        printf("Warn! Underflow!\n");
        return -1;
    }

    int result = p_queue->data[p_queue->front++]; // front의 값 반환 후 front 증가.
    BringForward(p_queue); // 앞 공간이 있으면 댕겨오기.
    return result;
}

// 실행 예제.
int main() {
    Queue myQueue;
    InitQueue(&myQueue);

    Enqueue(&myQueue, 10);
    Enqueue(&myQueue, 40);
    printf("Dequeue: %d\n", Dequeue(&myQueue));
    Enqueue(&myQueue, 50);
    Enqueue(&myQueue, 20);

    printf("Dequeue: %d\n", Dequeue(&myQueue));
    printf("Dequeue: %d\n", Dequeue(&myQueue));
    printf("Dequeue: %d\n", Dequeue(&myQueue)); // 언더플로우 발생 예시.

    return 0;
}

/*
직접 작성하며 느낀 점.
1. 배열 기반 큐는 앞 공간이 죽는 단점이 있어 댕겨오는 로직을 추가했다.
2. 하지만 매번 댕겨오는 것은 불필요하므로, 필요할 때만 실행되도록 만들었다.
3. 언더플로우는 rear < front일 때 발생한다.
4. 오버플로우는 rear가 QUEUE_SIZE - 1 이상일 때 발생한다.
*/
