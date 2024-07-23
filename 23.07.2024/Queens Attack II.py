def queensAttack(n, k, r_q, c_q, obstacles):
    obstacles = {(r, c) for r, c in obstacles}
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1), (-1, -1), (-1, 1), (1, -1), (1, 1)]
    count = 0

    for dr, dc in directions:
        r, c = r_q + dr, c_q + dc
        while 1 <= r <= n and 1 <= c <= n and (r, c) not in obstacles:
            count += 1
            r += dr
            c += dc

    return count

print(queensAttack(8, 0, 4, 4, []))
