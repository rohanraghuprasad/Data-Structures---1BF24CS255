#include <stdio.h>

#define MAX 10

int visited[MAX];
int adj[MAX][MAX];
int n;

void DFS(int v) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }


    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS Traversal starting from vertex 0:\n");
    DFS(0);
    for(int i=0; i<n; i++){
        if(visited[i]==0){
            printf("\nGraph is not connected\n");
            return;
        }
    }
    printf("\nGraph is connected\n");

    return 0;
}
