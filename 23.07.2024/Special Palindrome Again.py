def substrCount(n, s):
    count = 0
    for i in range(n):
        count += 1
        repeat_length = 0
        while i + 1 < n and s[i] == s[i + 1]:
            repeat_length += 1
            count += 1
            i += 1
        pointer = 1
        while i - pointer >= 0 and i + pointer < n and s[i - pointer] == s[i + pointer] and s[i - pointer] == s[i - 1]:
            count += 1
            pointer += 1
    return count

n = 7
s = "abcbaba"
print(substrCount(n, s))  # Expected output: 10
