#include <stdio.h>
#include <stdbool.h>
#define MAX_VERTICES 100
struct Queue 
{
int items[MAX_VERTICES];
int front;
int rear;
};

struct Queue* createQueue() 
{
struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
queue->front = -1;
queue->rear = -1;
return queue;
}

bool isEmpty(struct Queue* queue) 
{
return queue->rear == -1;
}
void enqueue(struct Queue* queue, int value) 
{
if (queue->rear == MAX_VERTICES - 1)
printf("Queue is full\n");
else {
if (queue->front == -1)
queue->front = 0;
queue->rear++;
queue->items[queue->rear] = value;
}
}

int dequeue(struct Queue* queue) {
int value;
if (isEmpty(queue)) {
printf("Queue is empty\n");
value = -1;
} else {
value = queue->items[queue->front];
queue->front++;
if (queue->front > queue->rear) 
{
queue->front = queue->rear = -1;
}
}
return value;
}

void breadthFirstSearch(int adjacencyMatrix[][MAX_VERTICES], int startVertex, int numVertices) {
struct Queue* queue = createQueue();
int visited[MAX_VERTICES] = {0};

printf("Breadth First Search starting from vertex %d:\n", startVertex);
printf("%d ", startVertex);
visited[startVertex] = 1;
enqueue(queue, startVertex);

while (!isEmpty(queue)) {
int currentVertex = dequeue(queue);

for (int i = 0; i < numVertices; i++) {
if (adjacencyMatrix[currentVertex][i] == 1 && !visited[i]) {
printf("%d ", i);
visited[i] = 1;
enqueue(queue, i);
}
}
}

printf("\n");
}

int main() {
int numVertices;
printf("Enter the number of vertices: ");
scanf("%d", &numVertices);

int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
printf("Enter the adjacency matrix:\n");
for (int i = 0; i < numVertices; i++) 
{
for (int j = 0; j < numVertices; j++) 
{
scanf("%d", &adjacencyMatrix[i][j]);
}
}
int startVertex;
printf("Enter the starting vertex: ");
scanf("%d", &startVertex);
breadthFirstSearch(adjacencyMatrix, startVertex, numVertices);
return 0;
}
