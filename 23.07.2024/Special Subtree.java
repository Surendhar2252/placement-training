import java.util.*;

class Edge implements Comparable<Edge> {
    int src, dest, weight;
    public int compareTo(Edge compareEdge) { return this.weight - compareEdge.weight; }
}

class Subset {
    int parent, rank;
}

public class KruskalMST {
    int V, E;
    Edge[] edge;

    KruskalMST(int v, int e) {
        V = v; E = e;
        edge = new Edge[E];
        for (int i = 0; i < e; ++i) edge[i] = new Edge();
    }

    int find(Subset[] subsets, int i) {
        if (subsets[i].parent != i) subsets[i].parent = find(subsets, subsets[i].parent);
        return subsets[i].parent;
    }

    void union(Subset[] subsets, int x, int y) {
        int xroot = find(subsets, x);
        int yroot = find(subsets, y);
        if (subsets[xroot].rank < subsets[yroot].rank) subsets[xroot].parent = yroot;
        else if (subsets[xroot].rank > subsets[yroot].rank) subsets[yroot].parent = xroot;
        else {
            subsets[yroot].parent = xroot;
            subsets[xroot].rank++;
        }
    }

    void kruskalMST() {
        Edge[] result = new Edge[V];
        int e = 0, i = 0;
        for (i = 0; i < V; ++i) result[i] = new Edge();
        Arrays.sort(edge);
        Subset[] subsets = new Subset[V];
        for (i = 0; i < V; ++i) subsets[i] = new Subset();
        for (int v = 0; v < V; ++v) {
            subsets[v].parent = v;
            subsets[v].rank = 0;
        }
        i = 0;
        while (e < V - 1) {
            Edge next_edge = edge[i++];
            int x = find(subsets, next_edge.src);
            int y = find(subsets, next_edge.dest);
            if (x != y) {
                result[e++] = next_edge;
                union(subsets, x, y);
            }
        }
        int minCost = 0;
        for (i = 0; i < e; ++i) minCost += result[i].weight;
        System.out.println(minCost);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int V = sc.nextInt();
        int E = sc.nextInt();
        KruskalMST graph = new KruskalMST(V, E);
        for (int i = 0; i < E; i++) {
            graph.edge[i].src = sc.nextInt() - 1;
            graph.edge[i].dest = sc.nextInt() - 1;
            graph.edge[i].weight = sc.nextInt();
        }
        graph.kruskalMST();
    }
}
