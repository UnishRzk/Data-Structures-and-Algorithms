#include <stdio.h>

#define MAX 100

void DFS(int adj[MAX][MAX], int visited[MAX], int V, int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < V; i++) {
        if (adj[vertex][i] == 1 && !visited[i]) {
            DFS(adj, visited, V, i);
        }
    }
}

int main() {
    int V, adj[MAX][MAX], visited[MAX] = {0}, start;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter adjacency matrix (0 or 1 only):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter starting vertex (0 to %d): ", V - 1);
    scanf("%d", &start);

    printf("DFS Traversal starting from vertex %d:\n", start);
    DFS(adj, visited, V, start);

    return 0;
}
