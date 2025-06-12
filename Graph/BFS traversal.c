#include <stdio.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;

void enqueue(int vertex) {
    if (rear == MAX - 1)
        return;
    if (front == -1) front = 0;
    queue[++rear] = vertex;
}

int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

int isEmpty() {
    return front == -1 || front > rear;
}

void BFS(int adj[MAX][MAX], int visited[MAX], int V, int start) {
    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal starting from vertex %d:\n", start);

    while (!isEmpty()) {
        int u = dequeue();
        printf("%d ", u);

        for (int v = 0; v < V; v++) {
            if (adj[u][v] == 1 && !visited[v]) {
                enqueue(v);
                visited[v] = 1;
            }
        }
    }
    printf("\n");
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

    BFS(adj, visited, V, start);

    return 0;
}
