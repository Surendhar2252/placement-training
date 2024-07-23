def fibonacciModified(t1, t2, n):
    for _ in range(n - 2):
        next_term = t1 + t2 * t2
        t1, t2 = t2, next_term
    return t2

t1 = 0
t2 = 1
n = 5
print(fibonacciModified(t1, t2, n))  # Expected output: 5
