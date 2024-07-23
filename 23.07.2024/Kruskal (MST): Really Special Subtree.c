#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int src, dest, weight;
};

struct subset {
    int parent, rank;
};

int compare(const void *a, const void *b) {
    return ((struct Edge *)a)->weight > ((struct Edge *)b)->weight;
}

int find(struct subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

void KruskalMST(struct Edge edges[], int V, int E) {
    struct Edge result[V];
    qsort(edges, E, sizeof(edges[0]), compare);
    struct subset *subsets = (struct subset *)malloc(V * sizeof(struct subset));
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    int e = 0, i = 0;
    while (e < V - 1 && i < E) {
        struct Edge next_edge = edges[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }
    int minCost = 0;
    for (i = 0; i < e; ++i)
        minCost += result[i].weight;
    printf("%d\n", minCost);
    free(subsets);
}

int main() {
    int V, E;
    scanf("%d%d", &V, &E);
    struct Edge *edges = (struct Edge *)malloc(E * sizeof(struct Edge));
    for (int i = 0; i < E; i++) {
        scanf("%d%d%d", &edges[i].src, &edges[i].dest, &edges[i].weight);
        edges[i].src--; edges[i].dest--;
    }
    KruskalMST(edges, V, E);
    free(edges);
    return 0;
}
