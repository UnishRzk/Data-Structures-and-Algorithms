	#include <stdio.h>
	
	#define MAX 100
	
	int graph[MAX][MAX], visited[MAX];
	
	void dfs(int node, int n) {
	    printf("%d ", node);
	    visited[node] = 1;
	
	    for (int i = 0; i < n; i++) {
	        if (graph[node][i] && !visited[i]) {
	            dfs(i, n);
	        }
	    }
	}
	
	int main() {
	    int n, start;
	
	    printf("Enter number of vertices: ");
	    scanf("%d", &n);
	
	    printf("Enter adjacency matrix:\n");
	    for (int i = 0; i < n; i++)
	        for (int j = 0; j < n; j++)
	            scanf("%d", &graph[i][j]);
	
	    printf("Enter starting vertex: ");
	    scanf("%d", &start);
	
	    printf("DFS Traversal: ");
	    dfs(start, n);
	    printf("\n");
	
	    return 0;
	}
