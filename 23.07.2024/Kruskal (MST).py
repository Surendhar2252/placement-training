def kruskal(n, edges):
    parent = list(range(n+1))

    def find(x):
        if parent[x] != x:
            parent[x] = find(parent[x])
        return parent[x]

    edges.sort(key=lambda x: x[2])
    mst_cost = 0
    for u, v, w in edges:
        root_u, root_v = find(u), find(v)
        if root_u != root_v:
            mst_cost += w
            parent[root_u] = root_v

    return mst_cost

edges = [(1, 2, 3), (1, 3, 2), (3, 4, 4)]
print(kruskal(4, edges))
