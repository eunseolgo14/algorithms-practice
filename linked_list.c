#include <stdio.h>
#include <stdlib.h>

// 연결 리스트 노드 구조체 정의.
typedef struct LinkedNode {
    int data;                  // 노드 데이터.
    struct LinkedNode* p_next; // 다음 노드 포인터.
} LinkedNode;

// 새 노드 생성 함수.
LinkedNode* CreateNode(int value) {
    LinkedNode* this_node = (LinkedNode*)malloc(sizeof(LinkedNode));
    if (this_node == NULL) { // 메모리 할당 실패 체크.
        printf("Error! Memory allocation failed.\n");
        exit(1);
    }
    this_node->data = value;
    this_node->p_next = NULL;
    return this_node;
}

// 맨 앞에 노드 삽입.
void InsertFront(LinkedNode** target, int value) {
    LinkedNode* new_head = CreateNode(value);
    new_head->p_next = *target;
    *target = new_head;
}

// 맨 뒤에 노드 삽입.
void InsertEnd(LinkedNode* target, int value) {
    while (target->p_next != NULL) {
        target = target->p_next;
    }
    target->p_next = CreateNode(value);
}

// 특정 위치(index)에 노드 삽입.
void InsertMiddle(LinkedNode** target, int index, int value) {
    if (index <= 0) {
        InsertFront(target, value);
        return;
    }

    LinkedNode* p_head = *target;
    for (int i = 0; i < (index - 1); i++) {
        if (p_head->p_next == NULL) { // index가 리스트 길이보다 클 때.
            return;
        }
        p_head = p_head->p_next;
    }

    LinkedNode* new_node = CreateNode(value);
    new_node->p_next = p_head->p_next;
    p_head->p_next = new_node;
}

// 리스트 출력 함수.
void PrintList(LinkedNode* head) {
    LinkedNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->p_next;
    }
    printf("NULL\n");
}

// 메모리 해제 함수.
void FreeList(LinkedNode* head) {
    LinkedNode* current = head;
    while (current != NULL) {
        LinkedNode* temp = current;
        current = current->p_next;
        free(temp);
    }
}

// 실행 예제.
int main() {
    LinkedNode* head_node = CreateNode(10);

    InsertEnd(head_node, 90);
    InsertEnd(head_node, 30);
    InsertFront(&head_node, 20);
    InsertEnd(head_node, 50);
    InsertMiddle(&head_node, 2, 40);

    printf("Linked List: ");
    PrintList(head_node);

    FreeList(head_node); // 메모리 해제.
    return 0;
}

/*
직접 작성하며 느낀 점.
1. 맨 앞이나 중간 삽입은 헤드 노드 주소가 바뀔 수 있어 이중포인터로 받아야 한다.
2. 맨 뒤 삽입은 다음을 가리키는 포인터가 없을 때까지 next를 타고 이동한다.
3. malloc을 통한 공간 할당 없이는 실제 메모리 주소를 받을 수 없다.
*/