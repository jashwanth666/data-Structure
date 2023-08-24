#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10

// Queue structure
typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Initialize queue
void initQueue(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Check if queue is empty
bool isEmpty(Queue *queue) {
    return queue->front == -1;
}

// Check if queue is full
bool isFull(Queue *queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

// Enqueue an element into the queue
void enqueue(Queue *queue, int value) {
    if (!isFull(queue)) {
        if (isEmpty(queue)) {
            queue->front = 0;
        }
        queue->rear = (queue->rear + 1) % MAX_SIZE;
        queue->data[queue->rear] = value;
    } else {
        printf("Queue is full. Cannot enqueue %d.\n", value);
    }
}

// Dequeue an element from the queue
int dequeue(Queue *queue) {
    if (!isEmpty(queue)) {
        int value = queue->data[queue->front];
        if (queue->front == queue->rear) {
            queue->front = -1;
            queue->rear = -1;
        } else {
            queue->front = (queue->front + 1) % MAX_SIZE;
        }
        return value;
    } else {
        printf("Queue is empty.\n");
        return -1;
    }
}

// Display the elements in the queue
void display(Queue *queue) {
    if (!isEmpty(queue)) {
        int index = queue->front;
        printf("Queue elements: ");
        while (index != queue->rear) {
            printf("%d ", queue->data[index]);
            index = (index + 1) % MAX_SIZE;
        }
        printf("%d\n", queue->data[index]);
    } else {
        printf("Queue is empty.\n");
    }
}

int main() {
    Queue queue;
    initQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    display(&queue);

    printf("Dequeued: %d\n", dequeue(&queue));
    printf("Dequeued: %d\n", dequeue(&queue));

    display(&queue);

    return 0;
}
