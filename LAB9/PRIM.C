#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int min(int key[], int mstSet[], int V) {
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < V; v++)
        if (mstSet[v] == 0 && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

void print(int parent[], int graph[][100], int V) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

void prim(int graph[][100], int V) {
    int *parent = (int *)malloc(V * sizeof(int));
    int *key = (int *)malloc(V * sizeof(int));
    int *mstSet = (int *)malloc(V * sizeof(int));

    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = 0;

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = min(key, mstSet, V);
        mstSet[u] = 1;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    print(parent, graph, V);

    free(parent);
    free(key);
    free(mstSet);
}

int main() {
    int V;
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    int graph[100][100];

    printf("Enter the adjacency matrix for the graph (%dx%d):\n", V, V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("Edge weight [%d][%d]: ", i, j);
            scanf("%d", &graph[i][j]);
        }
    }
    prim(graph, V);
    return 0;
}

