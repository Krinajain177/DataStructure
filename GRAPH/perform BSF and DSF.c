#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_VERTICES 100
typedef struct Node
{
    int vertex;
    struct Node *next;
} Node;
typedef struct Graph
{
    Node *adjLists[MAX_VERTICES];
    int visited[MAX_VERTICES];
    int numVertices;
} Graph;
// Function prototypes
Graph *createGraph(int vertices);
void addEdge(Graph *graph, int src, int dest);
void bfs(Graph *graph, int startVertex);
void dfs(Graph *graph, int vertex);
void dfsUtil(Graph *graph, int vertex);
int main()
{
    // Default code
    printf("Practial-7\n");
    printf("Enrollment NO: 230130107052\n");
    printf("Krina Jain\n");
    printf("7.1 Write a program to perform BFS and DFS on given graph.\n");
    Graph *graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    printf("BFS starting from vertex 0:\n");
    bfs(graph, 0);
    // Reset visited array for DFS
    for (int i = 0; i < graph->numVertices; i++)
        graph->visited[i] = 0;
    printf("\nDFS starting from vertex 0:\n");
    dfs(graph, 0);
    return 0;
}
// Function to create a graph
Graph *createGraph(int vertices)
{
    Graph *graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;
    for (int i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}
// Function to add an edge to the graph
void addEdge(Graph *graph, int src, int dest)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
    newNode = malloc(sizeof(Node));
    newNode->vertex = src;
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode; // For undirected graph
}
// BFS algorithm
void bfs(Graph *graph, int startVertex)
{
    int queue[MAX_VERTICES], front = -1, rear = -1;
    graph->visited[startVertex] = 1;
    queue[++rear] = startVertex;
    while (front < rear)
    {
        int currentVertex = queue[++front];
        printf("%d ", currentVertex);
        Node *temp = graph->adjLists[currentVertex];
        while (temp)
        {
            int adjVertex = temp->vertex;
            if (!graph->visited[adjVertex])
            {
                graph->visited[adjVertex] = 1;
                queue[++rear] = adjVertex;
            }
            temp = temp->next;
        }
    }
}
// DFS algorithm
void dfs(Graph *graph, int vertex)
{
    graph->visited[vertex] = 1;
    printf("%d ", vertex);
    Node *temp = graph->adjLists[vertex];
    while (temp)
    {
        int adjVertex = temp->vertex;
        if (!graph->visited[adjVertex])
        {
            dfs(graph, adjVertex);
        }
        temp = temp->next;
    }
}