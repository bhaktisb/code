#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int vertex;
    struct Node *next;
};

struct Graph {
    int numVertices;
    struct Node **adjLists;
    int *visited;
};

struct Node *createNode(int v) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph *createGraph(int vertices) {
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = (struct Node **)malloc(vertices * sizeof(struct Node *));
    graph->visited = (int *)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; ++i) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void addEdge(struct Graph *graph, int src, int dest) {
    struct Node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void depthFirstSearchList(struct Graph *graph, int vertex) {
    struct Node *adjList = graph->adjLists[vertex];
    struct Node *temp = adjList;

    graph->visited[vertex] = 1;
    printf("%d ", vertex);

    while (temp != NULL) {
        int connectedVertex = temp->vertex;

        if (graph->visited[connectedVertex] == 0) {
            depthFirstSearchList(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

void breadthFirstSearchList(struct Graph *graph, int startVertex) {
    int queue[MAX];
    int front = -1, rear = -1;

    graph->visited[startVertex] = 1;
    queue[++rear] = startVertex;

    printf("BFS Traversal: ");
    printf("%d ", startVertex);

    while (front != rear) {
        int currentVertex = queue[++front];
        struct Node *temp = graph->adjLists[currentVertex];

        while (temp) {
            int adjVertex = temp->vertex;

            if (graph->visited[adjVertex] == 0) {
                printf("%d ", adjVertex);
                queue[++rear] = adjVertex;
                graph->visited[adjVertex] = 1;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

int main() {
    int vertices, edges, src, dest;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    struct Graph *graph = createGraph(vertices);

    printf("Enter edges (format: source destination):\n");
    for (int i = 0; i < edges; ++i) {
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    int startVertex;
    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    printf("DFS Traversal: ");
    depthFirstSearchList(graph, startVertex);
    printf("\n");

    for (int i = 0; i < vertices; ++i) {
        graph->visited[i] = 0;
    }

    breadthFirstSearchList(graph, startVertex);

    return 0;
}

