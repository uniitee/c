#include <stdio.h>
#include <stdlib.h>
// Structure for an adjacency list node
struct Node{
    int vertex;
    struct Node *next;
};
// Structure for the graph
struct Graph{
    int numVertices;
    struct Node **adjLists;
};
// Queue structure for BFS
struct Queue{
    int items[100];
    int front;
    int rear;
};
// Function to create a new adjacency list node
struct Node *createNode(int vertex){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}
// Function to create a graph
struct Graph *createGraph(int vertices){
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    // Create an array of adjacency lists
    graph->adjLists = (struct Node **)malloc(vertices * sizeof(struct Node *));
    // Initialize each adjacency list as empty
    for (int i = 0; i < vertices; i++){
        graph->adjLists[i] = NULL;
    }
    return graph;
}
// Function to add an edge to the graph
void addEdge(struct Graph *graph, int src, int dest){
    // Add an edge from src to dest
    struct Node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
    // Since the graph is undirected, add an edge from dest to src as well
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}
// Function to initialize a queue
struct Queue *createQueue(){
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}
// Function to check if the queue is empty
int isEmpty(struct Queue *q){
    return q->front == -1;
}
// Function to add an element to the queue
void enqueue(struct Queue *q, int value){
    if (q->rear == 99){
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(q)){
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}
// Function to remove an element from the queue
int dequeue(struct Queue *q){
    if (isEmpty(q)){
        printf("Queue is empty\n");
        return -1;
    }
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear){
        q->front = q->rear = -1; // Reset the queue
    }
    return item;
}
// Breadth First Search algorithm
void bfs(struct Graph *graph, int startVertex){
    struct Queue *q = createQueue();
    int *visited = (int *)malloc(graph->numVertices * sizeof(int));
    // Mark all vertices as not visited
    for (int i = 0; i < graph->numVertices; i++){
        visited[i] = 0;
    }
    // Mark the starting vertex as visited and enqueue it
    visited[startVertex] = 1;
    enqueue(q, startVertex);
    while (!isEmpty(q)){
        // Dequeue a vertex from the queue and print it
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);
        // Get all adjacent vertices of the dequeued vertex
        struct Node *temp = graph->adjLists[currentVertex];
        while (temp){
            int adjacentVertex = temp->vertex;
            if (!visited[adjacentVertex]){
                visited[adjacentVertex] = 1; // Mark as visited
                enqueue(q, adjacentVertex);  // Enqueue the vertex
            }
            temp = temp->next;
        }
    }
    free(visited);
    free(q);
}
// Main function
int main(){
    struct Graph *graph = createGraph(5); // Create a graph with 5 vertices
    // Adding edges (undirected graph)
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    // Perform BFS starting from vertex 0
    printf("Breadth First Search (BFS) starting from vertex 0:\n");
    bfs(graph, 0);
    // Free allocated memory
    for (int i = 0; i < graph->numVertices; i++){
        struct Node *temp = graph->adjLists[i];
        while (temp){
            struct Node *prev = temp;
            temp = temp->next;
            free(prev);
        }
    }
    return 0;
}