import sys

def tich_lon_nhat(a):
    if not a:
        return 0
    max_so_far = a[0]
    curr_max = a[0]
    curr_min = a[0]

    for x in a[1:]:
        if x < 0:
            curr_max, curr_min = curr_min, curr_max
        curr_max = max(x, curr_max * x)
        curr_min = min(x, curr_min * x)
        max_so_far = max(max_so_far, curr_max)
    return max_so_far

def tich_lon_nhat_n2(a):
    n = len(a)
    max_prod = a[0]
    for i in range(n):
        p = 1
        for j in range(i, n):
            p *= a[j]
            max_prod = max(max_prod, p)
    return max_prod

if __name__ == "__main__":
    input_data = sys.stdin.read().split()
    if input_data:
        n = int(input_data[0])
        a = [int(x) for x in input_data[1:n+1]]
        print(tich_lon_nhat(a))