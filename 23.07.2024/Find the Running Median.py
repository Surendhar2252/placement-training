import heapq

def runningMedian(a):
    lowers, highers = [], []
    medians = []
    for num in a:
        heapq.heappush(lowers, -num) if not lowers or num <= -lowers[0] else heapq.heappush(highers, num)
        if len(lowers) > len(highers) + 1:
            heapq.heappush(highers, -heapq.heappop(lowers))
        if len(highers) > len(lowers):
            heapq.heappush(lowers, -heapq.heappop(highers))
        if len(lowers) == len(highers):
            medians.append((-lowers[0] + highers[0]) / 2)
        else:
            medians.append(-lowers[0])
    return medians

a = [12, 4, 5, 3, 8, 7]
print(runningMedian(a))
