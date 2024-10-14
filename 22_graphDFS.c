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
    int *visited; // To keep track of visited vertices
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
    graph->visited = (int *)malloc(vertices * sizeof(int));
    // Initialize each adjacency list as empty and visited array
    for (int i = 0; i < vertices; i++){
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0; // Mark all vertices as not visited
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
// Depth First Search algorithm
void dfs(struct Graph *graph, int vertex){
    // Mark the current vertex as visited and print it
    graph->visited[vertex] = 1;
    printf("%d ", vertex);
    // Recur for all the vertices adjacent to this vertex
    struct Node *temp = graph->adjLists[vertex];
    while (temp){
        int connectedVertex = temp->vertex;
        if (!graph->visited[connectedVertex]){
            dfs(graph, connectedVertex);
        }
        temp = temp->next;
    }
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
    // Perform DFS starting from vertex 0
    printf("Depth First Search (DFS) starting from vertex 0:\n");
    dfs(graph, 0);
    // Free allocated memory (not shown here for brevity)
    return 0;
}
