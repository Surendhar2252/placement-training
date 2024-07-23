def reverseShuffleMerge(s):
    from collections import Counter
    counter = Counter(s)
    required = {char: count//2 for char, count in counter.items()}
    result = []
    available = Counter(s)

    for char in reversed(s):
        if required[char] > 0:
            while result and result[-1] > char and available[result[-1]] > required[result[-1]]:
                required[result.pop()] += 1
            result.append(char)
            required[char] -= 1
        available[char] -= 1

    return ''.join(result)

print(reverseShuffleMerge("eggegg"))
