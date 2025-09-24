#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 인접 리스트의 노드 구조체 정의.
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// 그래프 구조체 정의.
typedef struct Graph {
    int numVertices;      // 정점 개수.
    Node** adjList;       // 인접 리스트.
    bool* visited;        // 방문 여부 배열.
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
    graph->visited = (bool*)malloc(vertices * sizeof(bool));

    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
        graph->visited[i] = false;
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

// DFS (재귀).
void DFS(Graph* graph, int vertex) {
    graph->visited[vertex] = true; // 방문 처리.
    printf("%d ", vertex);

    Node* temp = graph->adjList[vertex];
    while (temp) {
        int adjVertex = temp->vertex;
        if (!graph->visited[adjVertex]) {
            DFS(graph, adjVertex);
        }
        temp = temp->next;
    }
}

// 그래프 메모리 해제.
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
    free(graph->visited);
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

    printf("DFS Traversal starting from vertex 0:\n");
    DFS(graph, 0);

    FreeGraph(graph);
    return 0;
}

//DFS Traversal starting from vertex 0:
//0 2 4 1 3

/*
깊.우.탐 포인트.
1. DFS는 방문한 정점을 전역 visited 배열로 관리한다.
2. 재귀 호출 전에 visited[vertex] = true로 체크해야 무한 루프를 방지한다.
3. 인접 리스트 구조를 쓰면 그래프 메모리 효율성이 높아진다.
*/
