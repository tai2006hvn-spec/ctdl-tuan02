import sys

dem_de_quy = 0

def fib_de_quy(n):
    global dem_de_quy
    dem_de_quy += 1
    if n <= 2:
        return 1
    return fib_de_quy(n - 1) + fib_de_quy(n - 2)

def fib_ghi_nho(n, memo=None):
    if memo is None:
        memo = {}
    if n <= 2:
        return 1
    if n in memo:
        return memo[n]
    memo[n] = fib_ghi_nho(n - 1, memo) + fib_ghi_nho(n - 2, memo)
    return memo[n]

def fib_lap(n):
    if n <= 2:
        return 1
    a, b = 1, 1
    for _ in range(3, n + 1):
        a, b = b, a + b
    return b

if __name__ == "__main__":
    input_data = sys.stdin.read().split()
    if input_data:
        n = int(input_data[0])
        if n >= 93:
            print("tran long long -- phai phat hien va bao")
        else:
            f_val = fib_lap(n)
            if n <= 30:
                dem_de_quy = 0
                fib_de_quy(n)
                print(f"F = {f_val}, so loi goi = {dem_de_quy}")
            else:
                so_loi_goi = 2 * f_val - 1
                print(f"F = {f_val}, so loi goi = {so_loi_goi}")