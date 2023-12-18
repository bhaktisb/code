#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue {
    int front, rear, size;
    int array[MAX_SIZE];
};

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->size = 0;
    queue->rear = MAX_SIZE - 1;
    return queue;
}

int isFull(struct Queue* queue) {
    return (queue->size == MAX_SIZE);
}

int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full, cannot enqueue.\n");
        return;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->array[queue->rear] = item;
    queue->size++;
    printf("%d enqueued to the queue.\n", item);
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty, cannot dequeue.\n");
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % MAX_SIZE;
    queue->size--;
    return item;
}

int front(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }
    return queue->array[queue->front];
}

int rear(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }
    return queue->array[queue->rear];
}

int main() {
    struct Queue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    printf("Front element: %d\n", front(queue));
    printf("Rear element: %d\n", rear(queue));

    printf("%d dequeued from the queue.\n", dequeue(queue));

    printf("Front element after dequeue: %d\n", front(queue));
    printf("Rear element after dequeue: %d\n", rear(queue));

    return 0;
}
