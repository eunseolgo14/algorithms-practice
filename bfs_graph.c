#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// 인접 리스트의 노드 구조체 정의.
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// 그래프 구조체 정의.
typedef struct Graph {
    int numVertices;      // 정점 개수.
    Node** adjList;       // 인접 리스트.
} Graph;

// 새 노드 생성 함수.
Node* CreateNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// 그래프 생성 함수.
Graph* CreateGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjList = (Node**)malloc(vertices * sizeof(Node*));

    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

// 무방향 그래프에 간선 추가 함수.
void AddEdge(Graph* graph, int src, int dest) {
    // src → dest.
    Node* newNode = CreateNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // dest → src (양방향).
    newNode = CreateNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// BFS (큐 사용).
void BFS(Graph* graph, int startVertex) {
    bool visited[MAX_VERTICES] = {false}; // 지역적인 visited 배열.
    int queue[MAX_VERTICES];              // 큐 배열.
    int front = 0, rear = 0;              // 큐 포인터.

    visited[startVertex] = true;          // 시작 정점 방문 처리.
    queue[rear++] = startVertex;          // 큐에 삽입.

    while (front < rear) {                // 큐가 빌 때까지 반복.
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        Node* temp = graph->adjList[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;    // 방문 처리.
                queue[rear++] = adjVertex;    // 큐에 삽입.
            }
            temp = temp->next; // 다음 인접 노드로 이동.
        }
    }
}

// 그래프 메모리 해제 함수.
void FreeGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjList[i];
        while (temp) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->adjList);
    free(graph);
}

// 실행 예제.
int main() {
    int vertices = 5;
    Graph* graph = CreateGraph(vertices);

    AddEdge(graph, 0, 1);
    AddEdge(graph, 0, 2);
    AddEdge(graph, 1, 3);
    AddEdge(graph, 1, 4);
    AddEdge(graph, 2, 4);

    printf("BFS Traversal starting from vertex 0:\n");
    BFS(graph, 0);

    FreeGraph(graph);
    return 0;
}

/*
넓.우.탐 포인트.
1. BFS는 visited 배열을 지역적으로 관리해 큐와 함께 사용한다.
2. 큐에 넣고 반복 → while(front < rear) 구조로 탐색한다.
3. 큐에 넣기 전에 visited[adjVertex] = true로 체크해야 중복 방문을 막을 수 있다.
4. temp = temp->next가 없으면 무한 루프에 빠진다.
*/
