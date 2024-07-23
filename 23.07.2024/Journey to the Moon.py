def journeyToMoon(n, astronaut):
    from collections import defaultdict, deque
    def bfs(start):
        queue, count = deque([start]), 0
        while queue:
            node = queue.popleft()
            if node not in visited:
                visited.add(node)
                count += 1
                queue.extend(graph[node])
        return count

    graph = defaultdict(list)
    for u, v in astronaut:
        graph[u].append(v)
        graph[v].append(u)

    visited = set()
    components = [bfs(i) for i in range(n) if i not in visited]
    pairs = sum(a * b for i, a in enumerate(components) for b in components[i+1:])
    return pairs

print(journeyToMoon(5, [(0, 1), (2, 3), (0, 4)]))
