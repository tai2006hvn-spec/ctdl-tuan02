import sys
import time

def cach1(a):
    n = len(a)
    max_sum = -float('inf')
    for i in range(n):
        for j in range(i, n):
            s = sum(a[i:j+1])
            if s > max_sum: max_sum = s
    return max_sum

def cach2(a):
    n = len(a)
    max_sum = -float('inf')
    for i in range(n):
        s = 0
        for j in range(i, n):
            s += a[j]
            if s > max_sum: max_sum = s
    return max_sum

def kadane(a):
    max_sum = a[0]
    current_sum = a[0]
    for x in a[1:]:
        current_sum = max(x, current_sum + x)
        max_sum = max(max_sum, current_sum)
    return max_sum

if __name__ == "__main__":
    input_data = sys.stdin.read().split()
    if input_data:
        n = int(input_data[0])
        a = [int(x) for x in input_data[1:n+1]]

        for name, func in [("Cach 1", cach1), ("Cach 2", cach2), ("Kadane", kadane)]:
            start = time.perf_counter()
            res = func(a)
            end = time.perf_counter()
            print(f"{name} time: {end - start:.6f}s (Ket qua: {res})")