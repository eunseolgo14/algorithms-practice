#include <stdio.h>

// 스택 최대 크기 정의.
#define STACK_SIZE 10

// 스택 구조체 정의.
typedef struct {
    int data[STACK_SIZE];
    int top;
} Stack;

// 스택 초기화 함수.
void InitStack(Stack* p_stack) {
    p_stack->top = -1; // 스택의 top을 초기 상태(-1)로 설정.
}

// 스택에 데이터 삽입 함수.
void Push(Stack* p_stack, int value) {
    if (p_stack->top >= STACK_SIZE - 1) { // 오버플로우 체크.
        printf("Warn! Overflow!\n");
        return;
    }
    p_stack->data[++(p_stack->top)] = value; // top을 증가시키고 값 삽입.
}

// 스택에서 데이터 꺼내기 함수.
int Pop(Stack* p_stack) {
    if (p_stack->top < 0) { // 언더플로우 체크.
        printf("Warn! Underflow!\n");
        return 0;
    }
    return p_stack->data[(p_stack->top)--]; // 현재 top 값을 반환 후 top 감소.
}

// 스택의 최상단 값 확인 함수.
int Peek(Stack* p_stack) {
    if (p_stack->top < 0) { // 빈 스택 체크.
        printf("Warn! The Stack is empty!\n");
        return 0;
    }
    return p_stack->data[p_stack->top]; // top 위치 값 반환.
}

// 실행 예제.
int main() {
    Stack myStack;
    InitStack(&myStack);

    Push(&myStack, 10);
    Push(&myStack, 20);
    Push(&myStack, 50);
    Push(&myStack, 30);

    printf("Peek top: %d\n", Peek(&myStack)); // 최상단 값 확인.
    printf("Pop: %d\n", Pop(&myStack)); // 데이터 꺼내기.
    printf("Pop: %d\n", Pop(&myStack)); // 데이터 꺼내기.
    printf("Peek top: %d\n", Peek(&myStack)); // 최상단 값 확인.

    return 0;
}

/*
직접 작성하며 느낀 점.
1. 스택 크기를 명확히 정의하려면 #define으로 상수를 설정하면 깔끔하다.
2. top 자체를 반환하는 것이 아니라 data[top]을 꺼내야 한다.
3. 언더플로우는 top이 -1일 때, 오버플로우는 top이 배열의 마지막 인덱스 이상일 때 발생한다.
*/
