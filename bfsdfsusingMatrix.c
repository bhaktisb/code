#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

int pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

void depthFirstSearchMatrix(int adjMatrix[MAX][MAX], int vertices, int startVertex) {
    int visited[MAX] = {0};
    push(startVertex);
    visited[startVertex] = 1;

    printf("DFS Traversal: ");
    printf("%d ", startVertex);

    while (top != -1) {
        int currentVertex = pop();

        for (int i = 0; i < vertices; ++i) {
            if (adjMatrix[currentVertex][i] && !visited[i]) {
                push(i);
                visited[i] = 1;
                printf("%d ", i);
            }
        }
    }
    printf("\n");
}

void breadthFirstSearchMatrix(int adjMatrix[MAX][MAX], int vertices, int startVertex) {
    int visited[MAX] = {0};
    int queue[MAX];
    int front = -1, rear = -1;

    visited[startVertex] = 1;
    queue[++rear] = startVertex;

    printf("BFS Traversal: ");
    printf("%d ", startVertex);

    while (front != rear) {
        int currentVertex = queue[++front];

        for (int i = 0; i < vertices; ++i) {
            if (adjMatrix[currentVertex][i] && !visited[i]) {
                queue[++rear] = i;
                visited[i] = 1;
                printf("%d ", i);
            }
        }
    }
    printf("\n");
}

int main() {
    int vertices, startVertex;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    int adjMatrix[MAX][MAX];

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    depthFirstSearchMatrix(adjMatrix, vertices, startVertex);
    breadthFirstSearchMatrix(adjMatrix, vertices, startVertex);

    return 0;
}

