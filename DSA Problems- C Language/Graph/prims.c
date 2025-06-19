#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF 9999

int main() {
    int V;
    int cost[MAX][MAX];
    int visited[MAX] = {0};
    int totalCost = 0;
    int edges = 0;

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the cost adjacency matrix (use %d for INF if no edge):\n", INF);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    visited[0] = 1; // Start from vertex 0

    printf("\nEdges in the Minimum Spanning Tree:\n");

    while (edges < V - 1) {
        int min = INF;
        int u = -1, v = -1;

        for (int i = 0; i < V; i++) {
            if (visited[i]) {
                for (int j = 0; j < V; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u != -1 && v != -1) {
            printf("%d -- %d == %d\n", u, v, cost[u][v]);
            totalCost += cost[u][v];
            visited[v] = 1;
            edges++;
        }
    }

    printf("Total cost of MST: %d\n", totalCost);

    return 0;
}
