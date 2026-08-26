import sys

def la_nguyen_to(x: int) -> bool:
    if x < 2:
        return False
    i = 2
    while i * i <= x:
        if x % i == 0:
            return False
        i += 1
    return True

def dem_va_tong_kiem_tra_tung_so(n: int):
    dem = 0
    tong = 0
    for i in range(2, n + 1):
        if la_nguyen_to(i):
            dem += 1
            tong += i
    return dem, tong

def sang_eratosthenes(n: int):
    if n < 2:
        return 0, 0
    is_prime = [True] * (n + 1)
    is_prime[0] = is_prime[1] = False
    p = 2
    while p * p <= n:
        if is_prime[p]:
            for i in range(p * p, n + 1, p):
                is_prime[i] = False
        p += 1
    dem = 0
    tong = 0
    for i in range(2, n + 1):
        if is_prime[i]:
            dem += 1
            tong += i
    return dem, tong

if __name__ == "__main__":
    mode = int(sys.argv[1]) if len(sys.argv) > 1 else 2
    input_data = sys.stdin.read().split()
    if input_data:
        n = int(input_data[0])
        if n <= 30:
            primes = [i for i in range(2, n + 1) if la_nguyen_to(i)]
            print(*primes)
        else:
            dem, tong = dem_va_tong_kiem_tra_tung_so(n) if mode == 1 else sang_eratosthenes(n)
            if n >= 1000000:
                print(f"so luong = {dem}, tong = {tong}")
            else:
                print(f"so luong = {dem}")