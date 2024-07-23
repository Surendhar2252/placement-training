def getMinimumCost(k, c):
    c.sort(reverse=True)
    total_cost = 0
    previous_purchases = [0] * k
    for i in range(len(c)):
        total_cost += (previous_purchases[i % k] + 1) * c[i]
        previous_purchases[i % k] += 1
    return total_cost

k = 3
c = [2, 5, 6]
print(getMinimumCost(k, c))
