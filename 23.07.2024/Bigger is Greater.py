def biggerIsGreater(w):
    i = len(w) - 2
    while i >= 0 and w[i] >= w[i+1]:
        i -= 1
    if i == -1:
        return "no answer"
    j = len(w) - 1
    while w[j] <= w[i]:
        j -= 1
    w = list(w)
    w[i], w[j] = w[j], w[i]
    w = w[:i+1] + w[i+1:][::-1]
    return ''.join(w)

print(biggerIsGreater("ab"))
