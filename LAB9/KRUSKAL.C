#include <stdio.h>
#include <stdlib.h>
#include "mergesort.c"  

typedef struct {
    int u, v, weight;
} Edge;

int find_set(int v, int parent[]) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v], parent);
}

void union_sets(int a, int b, int parent[], int rank[]) {
    a = find_set(a, parent);
    b = find_set(b, parent);
    if (a != b) {
        if (rank[a] < rank[b]) {
            int temp = a; a = b; b = temp;
        }
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}

int main() {
    int n, m;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &m);

    Edge *edges = (Edge *)malloc(m * sizeof(Edge));
    printf("Enter edges (u v weight) one per line:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    merge_sort(edges, 0, m - 1);  
    
    int parent[n], rank[n];
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int cost = 0;
    printf("Edges in MST:\n");
    for (int i = 0; i < m; i++) {
        if (find_set(edges[i].u, parent) != find_set(edges[i].v, parent)) {
            cost += edges[i].weight;
            printf("%d - %d with weight %d\n", edges[i].u, edges[i].v, edges[i].weight);
            union_sets(edges[i].u, edges[i].v, parent, rank);
        }
    }

    printf("Total MST cost: %d\n", cost);
    free(edges);
    return 0;
}


